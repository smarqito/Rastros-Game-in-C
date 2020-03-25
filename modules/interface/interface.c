/** @file */
#include <string.h>
#include <stdio.h>
#include "interface.h"
#include "../logica/ficheiros.h"
#include "../logica/logica.h"



void mostrarTabuleiro (ESTADO *state) {
    int m,n;
    char i;
    for(n=0; n<2;n++)
        putchar(' ');
    putchar(' ');
    for(i='a';i<'i';i++)
        printf(COR_AZUL "___ " RESET);
    printf("\n");
    for (m=MAX_HOUSES-1; m>=0;m--) {
        printf(COR__AZUL_NEGRITO "%d" COR_AZUL " | ",m+1);
        for(n=0;n<MAX_HOUSES;n++) {
            printf("%c" COR_AZUL " | ", converteCasa(state->tab[m][n])); // imprime a casa na linha de comandos
        }
        printf("\n");
        for(n=0; n<2;n++)
            putchar(' ');
        putchar('|');
        for(i='a';i<'i';i++)
            printf(COR_AZUL "___|" RESET );
        printf("\n");
    }
    for(n=0; n<4;n++)
        putchar(' ');
    for(i='a';i<'i';i++)
        printf(COR__AZUL_NEGRITO "%c   ",i);
    putchar('\n');
}