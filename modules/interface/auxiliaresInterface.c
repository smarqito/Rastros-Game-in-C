/** @file */

#include <stdio.h>
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
    printf("%-23s mostra este menú.\n","ajuda");
    printf("%-23s ver autores.\n","autores");
    printf("%-23s sair do jogo.\n\n", "Q");
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
            "pos",
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
    printf("Mariana Marques - a#####@alunos.uminho.pt\n");
    putchar('\n');
}

int confirmaSaida () {
    char linha[BUF_SIZE], sair[2];
    int r=0;
    printf("Tem a certeza que pretende sair?\n");
    printf("S -> Sair; N -> Voltar ao menu\n");

    if(fgets(linha,BUF_SIZE,stdin) == NULL) r=2;
    else {
        if(strlen(linha) == 2 && sscanf(linha, "%[S-S]",sair)==1)
            ;
        else if(strlen(linha) == 2 && sscanf(linha, "%[N-N]",sair) == 1)
            r=1;
        else printf("Opcao invalida");
    }
    if (r!=0 && r!=1) confirmaSaida();

    return r;
}