//
// Created by marco on 3/9/20.
//
#include <string.h>
#include <stdio.h>
#include "interface.h"

char converteCasa (CASA house) {
    char casa;
    switch (house) {
        case VAZIO:
            casa = '.';
            break;
        case BRANCA:
            casa = '*';
            break;
        case PRETA:
            casa = '#';
            break;
        case JOGADOR1:
            casa = '1';
            break;
        case JOGADOR2:
            casa ='2';
            break;
    }
    return casa;
}

void mostrarTabuleiro (ESTADO *state) {
    int m,n;
    char i;
    FILE *save;
    save = fopen("./temp.txt","w+");

    for(n=0; n<2;n++)
        putchar(' ');
    putchar(' ');
    for(i='a';i<'i';i++)
        printf("___ ");
    printf("\n");
    for (m=0; m<MAX_HOUSES;m++) {
        printf("%d | ",m+1);
        for(n=0;n<MAX_HOUSES;n++) {
            printf("%c | ", converteCasa(state->tab[m][n]));
            fprintf(save,"%c", converteCasa(state->tab[m][n]));
        }
        printf("\n");
        fprintf(save,"\n");
        for(n=0; n<2;n++)
            putchar(' ');
        putchar('|');
        for(i='a';i<'i';i++)
            printf("___|");
        printf("\n");
    }
    for(n=0; n<4;n++)
        putchar(' ');
    for(i='a';i<'i';i++)
        printf("%c   ",i);
    putchar('\n');
    fclose(save);
}