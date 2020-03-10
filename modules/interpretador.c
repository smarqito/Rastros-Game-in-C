//
// Created by marco on 3/9/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"

int instrucao (char *instr) {
    int i;
    char opcoes[MAX_INSTR][11] = {
            "coordenada",
            "gr",
            "ler",
            "movs",
            "jog",
            "pos",
            "Q"
    };

    for(i=0; i<MAX_INSTR && strcmp(opcoes[i],instr);i++);
    return (i==MAX_INSTR) ? 0 : (i+1);
}

int interpretador (ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2], espaco[2] = " ";
    char *instr, *arg;
    int iinstr;

    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 0;
    instr = strtok(linha,espaco);
    arg = strtok(NULL,espaco);
    instr[strlen(instr) - 1] = '\0';

    if (!(iinstr = instrucao(instr))) {
        printf("Opcao invalida!");
        return 0;
    }

    switch (iinstr)
    {
        case 1:
            printf("func coordenada\n");
            break;
        case 2:
            printf("func gravar\n");
            break;
        case 3:
            printf("func ler\n");
            break;
        case 4:
            printf("func movs\n");
            break;
        case 5:
            printf("func jogada do bot\n");
            break;
        case 6:
            printf("func pos antiga\n");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", col, lin) == 2) {
        COORDENADA coord = {*lin - '1', *col - 'a'};
        printf("%d %d", coord.coluna, coord.linha);
        //jogar(e,coord);
        //mostrarTabuleiro(e);
    }
    return 1;
}