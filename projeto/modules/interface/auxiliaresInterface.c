/** @file
 * @brief Funções auxiliares para a camada interface
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "../../globals/globals.h"


void pedeAjuda() {
    printf("\n%-25s Descrição","Instruções");
    printf("\n%-23s Permite entrar no modo de jogo.\n","jogar");
    printf("%-23s gravar o estado atual do jogo num ficheiro.\n","gr nome_do_ficheiro");
    printf("%-23s ler o estado de um jogo a partir de um ficheiro.\n","ler nome_do_ficheiro");
    printf("%-23s imprimir a lista de movimentos do jogo atual.\n","movs");
    printf("%-23s pedir ajuda ao bot para escolher a jogada atual.\n","jog");
    printf("%-23s visualizar uma posição anterior através do seu número.\n","pos numero_da_jogada");
    printf("%-23s iniciar um novo jogo. Perde o estado do jogo atual!\n","novo");
    printf("%-23s ativar jogo contra o bot\n","bot NIVEL");
    printf("%-23s mostra este menú.\n","ajuda");
    printf("%-23s ver autores.\n","autores");
    printf("%-23s sair do jogo.\n\n", "Q");
}

void digitos (int i, FILE *save){
    if(!save) save = stdout; 
    if (i+1 < 10) fprintf (save,"0%d: ", i+1);
    else fprintf(save, "%d: ", i+1);
}

int instrucao (char *instr) {
    int i=0;
    while(instr[i++]) if (instr[i] == '\n') instr[i] = '\0';
    char opcoes[MAX_INSTR][11] = { //!< Array bidimensional de instruções possíveis;
            "jogar",
            "gr",
            "ler",
            "movs",
            "jog",
            "jog2",
            "pos",
            "novo",
            "bot",
            "ajuda",
            "help",
            "autores",
            "Q"
    };

    for(i=0; i<MAX_INSTR && strcmp(opcoes[i],instr) != 0;i++);
    return (i==MAX_INSTR) ? 0 : (i+1);
}

void verAutores() {
    printf("Marco António Sousa - a62608@alunos.uminho.pt\n");
    printf("José Malheiro - a93271@alunos.uminho.pt\n");
    printf("Mariana Marques - a93198@alunos.uminho.pt\n");
    putchar('\n');
}

int confirmaSaida () {
    char linha[BUF_SIZE], sair[2];
    int r=0;
    printf("Tem a certeza que pretende sair?\n");
    printf("'S': Sair \n 'N': Voltar ao menu\n");

    if(fgets(linha,BUF_SIZE,stdin) == NULL) r=2;
    else {
        if(strlen(linha) == 2 && sscanf(linha, "%[S-S]",sair)==1)
            ;
        else if(strlen(linha) == 2 && sscanf(linha, "%[N-N]",sair) == 1)
            r=1;
        else {
            printf("Opcao invalida\n");
            r=2;
        }
    }
    if (r!=0 && r!=1) confirmaSaida();

    return r;
}

void congratulaVencedor (int vencedor) {
    printf(SUBLINHADO_ON COR_AMARELO_NEGRITO "Venceu o jogador %d\n\n" SUBLINHADO_OFF,vencedor);
}