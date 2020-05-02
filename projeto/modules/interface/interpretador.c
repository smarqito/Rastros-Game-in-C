/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"
#include "../logica/logica.h"
#include "../../../bot/auxiliaresBot.h"
#include "interface.h"
#include "auxiliaresInterface.h"
#include "../../globals/globals.h"
#include "ficheiros.h"

int jogarRastros(ESTADO *e, INPUT *input);


void imprimeComandos (ESTADO *state) {
    int numeroComandosAtual = numeroComandos(state)+1;
    if (numeroComandosAtual < 10) {
        printf("#0%d ",numeroComandosAtual);
    } else {
        printf("#%d ",numeroComandosAtual);
    }
}


int comandos (ESTADO *e, INPUT *input, int comando) {
    int r=0;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    switch (comando)
    {
        case 1: //!< Opção "jogar"
            mostrarTabuleiro(e);
            jogarRastros(e, input);
            r=1;
            break;
        case 2: //!< Opção "gr nomeficheiro"
            if(gravarJogo(e, strcat(dir, obterArgumentoComando(input, 1))) == 0) {
                printf(COR_VERMELHO NEGRITO_ON "Jogo gravado no ficheiro \"%s\".\n" RESET, obterArgumentoComando(input, 1));
            } else {
                printf("Não foi possível gravar o estado do jogo no ficheiro \"%s\". Tente novamente\n",obterArgumentoComando(input, 1));
            }
            break;
        case 3: //!< Opção "ler nomeficheiro"
            if(!(r = lerJogo(e,strcat(dir, obterArgumentoComando(input, 1)))))
                printf("O ficheiro "COR_VERDE_NEGRITO "%s" COR_AZUL " foi lido corretamente.\n\n",obterArgumentoComando(input, 1));//mostrarTabuleiro(e);
            else if(r==1) {
                promptFormata(COR_VERMELHO_NEGRITO);
                printf("O ficheiro que procura \""SUBLINHADO_ON"%s"SUBLINHADO_OFF"\" não existe.\n", obterArgumentoComando(input, 1));
                r=0;
            } else {
                promptFormata(COR_VERMELHO_NEGRITO);
                printf("O ficheiro \""SUBLINHADO_ON"%s"SUBLINHADO_OFF"\" não foi lido corretamente.\n", obterArgumentoComando(input, 1));
                printf("Verifique se o ficheiro está bem construído.\n");
            } 
            break;
        case 4: //!< Opção "movs"
            if(!lerMovimentos(e)) {
            }
            break;
        case 5: //!< Opção "jog"
            if(obterNivelBot(e) != 0)
                alteraNivelBot(e, 0);
            jogaBot(e);
            break;
        case 6:
            if(obterNivelBot(e) != 1)
                alteraNivelBot(e, 1);
            jogaBot(e);
            break;
        case 7: //!< Opção "pos #pos#"
            mostraPos(e,obterArgumentoComando(input, 1));
            break;
        case 8: //!< Opção "novo" inicia um novo jogo
            free(e);
            e=initState();
            break;
        case 9:
            if(obterArgumentoComando(input, 1)) {
                if (!lerEstadoBot(e)) alteraEstadoBot(e);
                alteraNivelBot(e, atoi(obterArgumentoComando(input, 1)));
            } else 
                alteraEstadoBot(e);
            printf("O bot encontra-se ");
            lerEstadoBot(e) ?
                printf(COR_VERDE_NEGRITO "ativado.\n")
                :
                printf(COR_VERMELHO_NEGRITO "desativado.\n");
            break;
        case 10: //!< Opção "ajuda"
        case 11: //!< Opção "help"
            pedeAjuda();
            break;
        case 12: //!< Opção "autores"
            verAutores();
            break;
        case 13: //!< Opção "Q" para sair
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

int jogarRastros (ESTADO *state, INPUT *input) {
    char linha[BUF_SIZE];
    char lin[2], col[2];
    int chegouFim, r=0;

    if((chegouFim=verificaFim(state))) {
        congratulaVencedor(chegouFim);
        return 1;
    } else {
        promptFormata(COR_VERMELHO_NEGRITO);
        imprimeComandos(state); //!< imprime o numero de comandos utilizados
        printf("PL%d (%d) > ", obterJogador(state), obterJogador(state) ? (obterNumeroJogadas(state)+1) : (obterNumeroJogadas(state)));
        promptFormata(COR_VERDE_NEGRITO);
        if(fgets(linha,BUF_SIZE,stdin) == NULL)
            return 1;
        if(strlen(linha) == 3 && sscanf(linha, "%1[a-h]%1[1-8]", col, lin) == 2) { //!< caso o input tenha 2 carateres lê a col e lin
            COORDENADA coord = {*lin - '1', *col - 'a'};
            r=jogar(state,coord);
        } else if (strlen(linha) == 2 && sscanf(linha, "%[Q-Q]",col) == 1 ) { //!< caso o input tenha 1 carater, verifica se é um 'Q'
            return 0;
        } else if (!divideInput(input, linha)) {
            comandos(state,input,instrucao(obterArgumentoComando(input,0)));
            r=1;
        } else {
            printf("Coordenada inválida. Tente novamente.\n");
        }
    }

    if (lerEstadoBot(state) && r==0 && numeroComandos(state)>0)  //!< Caso o jogo termine após o bot jogar!
        r=jogaBot(state);
    mostrarTabuleiro(state);
    jogarRastros(state, input);

    return r;
}



int interpretador (ESTADO *e) {

    char linha[BUF_SIZE];
    int iinstr,r;

    INPUT *input = initInput();


    printf(COR__AZUL_NEGRITO "Diga-nos a sua instrucao:\n");
    promptFormata(COR_AZUL);
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;

    //divide o input em comando e argumento
    r=divideInput(input, linha);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(obterArgumentoComando(input,0))) || r) {
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
            printf("Por favor reporte à equipa de programadores o que aconteceu.\n");
            promptFormata(COR_CIANO_NEGRITO);
            promptFormata(SUBLINHADO_ON);
            verAutores();
            promptFormata(SUBLINHADO_OFF);
            interpretador(e);
        }
    }
    return 0;
}