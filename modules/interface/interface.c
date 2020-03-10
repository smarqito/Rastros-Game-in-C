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
    }
    return casa;
}

void mostrarTabuleiro (ESTADO *state) {
    int m,n;
    char i;
    for(n=0; n<2;n++)
        putchar(' ');
    putchar(' ');
    for(i='a';i<'i';i++)
        printf("___ ");
    printf("\n");
    for (m=0; m<MAX_HOUSES;m++) {
        printf("%d | ",m+1);
        for(n=0;n<MAX_HOUSES;n++) {
            if (!m && n == 7) printf("2 | ");
            else if (m==7 && !n) printf("1 | ");
            else printf("%c | ", converteCasa(state->tab[m][n]));
        }
        printf("\n");
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
}