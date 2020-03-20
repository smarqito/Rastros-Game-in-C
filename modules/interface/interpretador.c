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

/**
 * @brief Compara se a instrução recebida pertence ao grupo de instruções possíveis
 *
 * @param instr instrução inserida pelo utilizador e que vai ser comparada.
 * @return 0 se não for possível. o índice + 1 caso a instrução exista.
 */

int instrucao (char *instr) {
    int i=0;
    while(instr[i++]) if (instr[i] == '\n') instr[i] = '\0';
    char opcoes[MAX_INSTR][11] = { //!< Array bidimensional de instruções possíveis
            "jogar",
            "gr",
            "ler",
            "movs",
            "jog",
            "pos",
            "ajuda",
            "help",
            "Q"
    };

    for(i=0; i<MAX_INSTR && strcmp(opcoes[i],instr);i++);
    return (i==MAX_INSTR) ? 0 : (i+1);
}

/**
 * @brief Permite jogar rastros até:
 *        Um jogador ganhar.
 *        O utilizador optar por voltar ao menú anterior.
 * @param state Apontador para o estado do programa.
 * @return 1 se houver algum erro. 0 sem erro.
 */
int jogarRastros (ESTADO *state) {
    char linha[BUF_SIZE];
    char lin[2], col[2];
    int chegouFim;
    imprimeComandos(state); //!< imprime o numero de comandos utilizados
    printf("PL%d (%d) > ",getPlayer(state),getNumberPlays(state));
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) { //!< caso o input tenha 2 carateres lê a col e lin
        COORDENADA coord = {*lin - '1', *col - 'a'};
        jogar(state,coord);
    } else if (strlen(linha) == 2 && sscanf(linha, "%[Q-Q]",col) == 1 ) { //!< caso o input tenha 1 carater, verifica se é um 'Q'
        interpretador(state);
        return 0;
    } else {
        printf("Coordenada inválida. Tente novamente.\n");
    }
    if((chegouFim=verificaFim(state))) {
        printf("Venceu o jogador %d.\n",chegouFim);
        interpretador(initState());
        return 1;
    } else {
        jogarRastros(state);
    }
}

/**
 * @brief Imprime a tabela de opções de comandos.
 */
void pedeAjuda() {
    printf("\n%-25s Descrição","Instruções");
    printf("\n%-23s Permite entrar no modo de jogo.\n","jogar");
    printf("%-23s gravar o estado atual do jogo num ficheiro.\n","gr nome_do_ficheiro");
    printf("%-23s ler o estado de um jogo a partir de um ficheiro.\n","ler nome_do_ficheiro");
    printf("%-23s imprimir a lista de movimentos do jogo atual.\n","movs");
    printf("%-23s pedir ajuda ao bot para escolher a jogada atual.\n","jog");
    printf("%-23s visualizar uma posição anterior através do seu número.\n","pos numero_da_jogada");
    printf("%-23s mostra este menú.\n","ajuda");
    printf("%-23s sair do jogo.\n\n", "Q");
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
    char col[2], lin[2], espaco[2] = " ";
    char *instr, *arg;
    int iinstr,r;
    printf("Diga-nos a sua instrucao:\n");
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 1;
    //divide o input em instrução e argumento
    instr = strtok(linha,espaco);
    arg = strtok(NULL,espaco);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(instr))) {
        pedeAjuda();
        printf("Opcao invalida!\n\n");
        interpretador(e);
        return 0;
    }
    switch (iinstr)
    {
        case 1: //!< Opção "jogar"
            mostrarTabuleiro(e);
            jogarRastros(e);
            break;
        case 2: //!< Opção "gr nomeficheiro"
            gravarJogo(e,arg);
            break;
        case 3: //!< Opção "ler nomeficheiro"
            if(!lerJogo(e,arg))
                interpretador(e);
            break;
        case 4: //!< Opção "movs"
            if(!lerMovimentos(e))
                interpretador(e);
            break;
        case 5: //!< Opção "jog"
            jogaBot(e);
            break;
        case 6: //!< Opção "pos #pos#"
            mostraPos(e,arg);
            break;
        case 7: //!< Opção "ajuda"
        case 8: //!< Opção "help"
            pedeAjuda();
            interpretador(e);
            break;
        case 9: //!< Opção "Q" para sair
            printf("Obrigado por jogar connosco! Até à próxima.\n");
            break;
        default:
            pedeAjuda();
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}