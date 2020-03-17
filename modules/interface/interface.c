//
// Created by marco on 3/9/20.
//
#include <string.h>
#include <stdio.h>
#include "interface.h"
#include "../logica/ficheiros.h"
#include "../logica/logica.h"

/*
  *  Imprime o tabuleiro em dois locais:
  *  - Na linha de comandos;
  *  - Num ficheiro temporário (de texto).
  *
  *  Método:
  *  1. Declara-se um apontador do tipo FILE;
  *  2. Abre-se o ficheiro (através da função fopen)
  *  3. Imprime-se o tabuleiro na linha de comandos (printf) e no ficheiro de texto (fprintf) (uma única passagem pela array tab);
  *      3.1. Utiliza-se a função converteCasa para, tal como o nome indica, converter uma CASA para um char.
  *  4. Fecha-se o ficheiro (fclose).
  *
  *  A impressão na linha de comandos encontra-se formatada para uma melhor leitura humana, enquanto que a impressão em
ficheiro está organizada para facilitar a leitura através de funções IO e criação de um novo ESTADO do programa.
 */
void mostrarTabuleiro (ESTADO *state) {
    int m,n;
    char i;
    for(n=0; n<2;n++)
        putchar(' ');
    putchar(' ');
    for(i='a';i<'i';i++)
        printf("___ ");
    printf("\n");
    for (m=MAX_HOUSES-1; m>=0;m--) {
        printf("%d | ",m+1);
        for(n=0;n<MAX_HOUSES;n++) {
            printf("%c | ", converteCasa(state->tab[m][n])); // imprime a casa na linha de comandos
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