/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"
#include "../logica/logica.h"
#include "../logica/bot.h"
#include "interface.h"
#include "auxiliaresInterface.h"
#include "../../globals/globals.h"
#include "ficheiros.h"

int jogarRastros(ESTADO *e, INPUT *input);


void imprimeComandos (ESTADO *state) {
    int numeroComandosAtual = numeroComandos(state);
    if (numeroComandosAtual < 10) {
        printf("#0%d ",numeroComandosAtual);
    } else {
        printf("#%d ",numeroComandosAtual);
    }
}


int comandos (ESTADO *e, INPUT *input, int comando) {
    int r=0;
    switch (comando)
    {
        case 1: //!< Opção "jogar"
            mostrarTabuleiro(e);
            jogarRastros(e, input);
            r=1;
            break;
        case 2: //!< Opção "gr nomeficheiro"
            if(gravarJogo(e,input->argumento)==0) {
                printf(COR_VERMELHO NEGRITO_ON "Jogo gravado no ficheiro \"%s\".\n" RESET, input->argumento);
            } else {
                printf("Não foi possível gravar o estado do jogo no ficheiro \"%s\". Tente novamente\n",input->argumento);
            }
            break;
        case 3: //!< Opção "ler nomeficheiro"
            if(lerJogo(e,input->argumento) == 0)
                mostrarTabuleiro(e);
            else
                printf("O ficheiro que procura \"%s\" não existe.\n", input->argumento);
            break;
        case 4: //!< Opção "movs"
            if(!lerMovimentos(e))
            break;
        case 5: //!< Opção "jog"
            jogaBot(e);
            break;
        case 6: //!< Opção "pos #pos#"
            mostraPos(e,input->argumento);
            break;
        case 7: //!< Opção "ajuda"
        case 8: //!< Opção "help"
            pedeAjuda();
            break;
        case 9: //!< Opção "autores"
            verAutores();
            break;
        case 10: //!< Opção "Q" para sair
            printf(COR__AZUL_NEGRITO "Obrigado por jogar connosco! Até à próxima.\n");
            r=1;
            break;
        default:
            pedeAjuda();
            printf("Opção inválida!\n");
            break;
    }
    return r;
}

int divideInput (INPUT *resposta, char *input){
    int r=0, nInstr;
    char espaco[2] = " ";

    resposta->comando = strtok(input,espaco);
    if (resposta->comando == NULL) r = 1;
    resposta->argumento = strtok(NULL,espaco);
    nInstr=instrucao(resposta->comando);
    if (resposta->argumento == NULL && (nInstr == 2 || nInstr == 3)) r = 1;
    return r;
}

int jogarRastros (ESTADO *state, INPUT *input) {
    char linha[BUF_SIZE];
    char lin[2], col[2];
    int chegouFim;
    promptFormata(COR_VERMELHO_NEGRITO);
    imprimeComandos(state); //!< imprime o numero de comandos utilizados
    printf("PL%d (%d) > ", obterJogador(state), obterNumeroJogadas(state));
    promptFormata(COR_VERDE_NEGRITO);
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { //!< caso o input tenha 2 carateres lê a col e lin
        COORDENADA coord = {*lin - '1', *col - 'a'};
        jogar(state,coord);
    } else if (strlen(linha) == 2 && sscanf(linha, "%[Q-Q]",col) == 1 ) { //!< caso o input tenha 1 carater, verifica se é um 'Q'
        return 0;
    } else if (!divideInput(input, linha)) {
        comandos(state,input,instrucao(input->comando));
    } else {
        printf("Coordenada inválida. Tente novamente.\n");
    }

    if((chegouFim=verificaFim(state))) {
        printf(SUBLINHADO_ON COR_AMARELO_NEGRITO "Venceu o jogador %d\n\n" SUBLINHADO_OFF,chegouFim);
        //interpretador(initState());
        return 1;
    } else {
        jogarRastros(state, input);
    }
}



int interpretador (ESTADO *e) {

    char linha[BUF_SIZE], sair[2];
    int iinstr,r;

    INPUT *input = (INPUT *) malloc (sizeof(INPUT));

    printf(COR__AZUL_NEGRITO "Diga-nos a sua instrucao:\n");
    promptFormata(COR_AZUL);
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;

    //divide o input em comando e argumento
    r=divideInput(input, linha);
    printf("erro de leitura da linha: %d\n", r);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(input->comando)) || r) {
        pedeAjuda();
        printf("Opcao invalida!\n\n");
        interpretador(e);
        return 0;
    } else {
        if((r=comandos(e,input,iinstr))==0) {
            interpretador(e);
        } else if(r==1) {
            r = confirmaSaida();
            if (r == 1) 
                interpretador(e);
        } else {
            printf("Aconteceu algo imprevisto. Por favor reporte à equipa de programadores.");
            verAutores();
        }
    }
    return 0;
}