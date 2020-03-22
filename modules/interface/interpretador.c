/** @file
 *  @brief Definição das função que permitem ao utilizador interagir com o programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"
#include "../logica/logica.h"
#include "../logica/bot.h"
#include "interface.h"
#include "../logica/ficheiros.h"
#include "auxiliaresInterface.h"

int jogarRastros(ESTADO *e, INPUT *input);



/** @brief Imprime os Comandos.
 *
 * @param state Apontador para o estado do programa;
 */

void imprimeComandos (ESTADO *state) {
    int numeroComandos = numero_comandos(state);
    if (numeroComandos < 10) {
        printf("#0%d ",numeroComandos);
    } else {
        printf("#%d ",numeroComandos);
    }
}




int comandos (ESTADO *e, INPUT *input, int comando) {
    int r=0;
    switch (comando)
    {
        case 1: //!< Opção "jogar"
            mostrarTabuleiro(e);
            jogarRastros(e, input);
            break;
        case 2: //!< Opção "gr nomeficheiro"
            if(!gravarJogo(e,input->argumento)) {
                printf(COR_VERMELHO NEGRITO_ON "Jogo gravado no ficheiro \"%s\".\n" RESET, input->argumento);
            }
            break;
        case 3: //!< Opção "ler nomeficheiro"
            if(!lerJogo(e,input->argumento))

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
        case 9: //!< Opção "Q" para sair
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
/**
 * @brief Divide um determinado input em comando e argumento.
 *
 * @param input Linha de texto inserida pelo utilizador.
 * @return 0 se sucesso
 */
int *divideInput (INPUT *resposta, char *input){
    int r=0;
    char espaco[2] = " ";

    resposta->comando = strtok(input,espaco);
    resposta->argumento = strtok(NULL,espaco);

    return 0;
}
/**
 * @brief Permite jogar rastros até:
 *        Um jogador ganhar.
 *        O utilizador optar por voltar ao menú anterior.
 * @param state Apontador para o estado do programa.
 * @return 1 se houver algum erro. 0 sem erro.
 */
int jogarRastros (ESTADO *state, INPUT *input) {
    char linha[BUF_SIZE];
    char lin[2], col[2];
    int chegouFim;
    promptFormata(COR_VERMELHO);
    imprimeComandos(state); //!< imprime o numero de comandos utilizados
    printf("PL%d (%d) > ",getPlayer(state),getNumberPlays(state));
    promptFormata(COR_VERDE_NEGRITO);
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { //!< caso o input tenha 2 carateres lê a col e lin
        COORDENADA coord = {*lin - '1', *col - 'a'};
        jogar(state,coord);
    } else if (strlen(linha) == 2 && sscanf(linha, "%[Q-Q]",col) == 1 ) { //!< caso o input tenha 1 carater, verifica se é um 'Q'
        return 0;
    } else if (!divideInput(input, linha)) {
        if(!comandos(state,input,instrucao(input->comando))) {
            jogarRastros(state,input);
        }
        else {
            return 0;
        }
    } else {
        printf("Coordenada inválida. Tente novamente.\n");
    }

    if((chegouFim=verificaFim(state))) {
        printf("Venceu o jogador %d.\n",chegouFim);
        //interpretador(initState());
        return 1;
    } else {
        jogarRastros(state, input);
    }
}



/**
 * @brief Principal interpretador de comandos do programa.
 *
 * Permite ao utilizador interagir com o programa, utilizando os comandos descritos na função pedeAjuda.
 * @param e Apontador para o estado do programa.
 * @return 1 se erro de leitura. 0 se sucesso.
 */
int interpretador (ESTADO *e) {

    char linha[BUF_SIZE];
    int iinstr,r;

    INPUT *input = (INPUT *) malloc (sizeof(INPUT));

    printf(COR__AZUL_NEGRITO "Diga-nos a sua instrucao:\n");
    promptFormata(COR_AZUL);
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;

    //divide o input em comando e argumento
    divideInput(input, linha);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(input->comando))) {
        pedeAjuda();
        printf("Opcao invalida!\n\n");
        interpretador(e);
        return 0;
    } else {
        if(comandos(e,input,iinstr)==0) {
            interpretador(e);
        }
    }
    return 0;
}