//
// Created by marco on 3/9/20.
//
#include <string.h>
#include <stdio.h>
#include "interface.h"

/*
 * Utiliza-se esta função para converter uma CASA para o tipo char correspondente:
 * 1. VAZIO: '.'
 * 2. BRANCA: '*'
 * 3. JOGADOR1: '1'
 * 4. JOGADOR2: '2'
 */
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
    FILE *save;
    save = fopen("./temp.txt","w+"); //abre o ficheiro temporário
    for(n=0; n<2;n++)
        putchar(' ');
    putchar(' ');
    for(i='a';i<'i';i++)
        printf("___ ");
    printf("\n");
    for (m=0; m<MAX_HOUSES;m++) {
        printf("%d | ",m+1);
        for(n=0;n<MAX_HOUSES;n++) {
            printf("%c | ", converteCasa(state->tab[m][n])); // imprime a casa na linha de comandos
            fprintf(save,"%c", converteCasa(state->tab[m][n])); // imprime a casa no ficheiro de texto temporário
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
    fclose(save); //fecha o ficheiro temporário
}