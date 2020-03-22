//
// Created by marco on 3/22/20.
//

#include <stdio.h>
#include "auxiliaresInterface.h"
#include "string.h"
#include "../../globals/globals.h"

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