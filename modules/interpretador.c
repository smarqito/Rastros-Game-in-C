//
// Created by marco on 3/9/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"
#include "logica/logica.h"
#include "interface/interface.h"

int instrucao (char *instr) {
    int i=0;
    while(instr[i++]) if (instr[i] == '\n') instr[i] = '\0';
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

    printf("Diga-nos a sua instrucao:\n");
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 0;
    //divide o input em instrução e argumento
    instr = strtok(linha,espaco);
    arg = strtok(NULL,espaco);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(instr))) {
        printf("Opcao invalida!");
        interpretador(e);
        return 0;
    }
    switch (iinstr)
    {
        case 1:
            if(strlen(arg) == 3 && sscanf(arg, "%[a-h]%[1-8]", col, lin) == 2) {
                COORDENADA coord = {*lin - '1', *col - 'a'};
                jogar(e,coord);
                mostrarTabuleiro(e);
            }
            interpretador(e);
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
        case 7:
            printf("exit");
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }

    return 1;
}