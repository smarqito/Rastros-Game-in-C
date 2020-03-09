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
    for (m=0; m<MAX_HOUSES;m++) {
        for(n=0;n<MAX_HOUSES;n++) {
            printf("%c ", converteCasa(state->tab[m][n]));
        }
        printf("\n");
    }
}