/** @file
 *  @brief Definição das função da camada de interface do programa.
 *
 */

#include <string.h>
#include <stdio.h>
#include "interface.h"
#include "../logica/ficheiros.h"
#include "../logica/logica.h"

/** @brief Mostra o tabuleiro.
  *
  *  Imprime o tabuleiro em dois locais: (1) Na linha de comandos (2) Num ficheiro temporário (de texto);
  *
  *  Método:
  *  1. Declara-se um apontador do tipo FILE;
  *  2. Abre-se o ficheiro (Através da função fopen);
  *  3. Imprime-se o tabuleiro na linha de comandos (printf) e no ficheiro de texto (fprintf) (uma única passagem pela array tab);
  *      3.1. Utiliza-se a função converteCasa para, tal como o nome indica, converter uma CASA para um char.
  *  4. Fecha-se o ficheiro (fclose).
  *
  *  A impressão na linha de comandos encontra-se formatada para uma melhor leitura humana, enquanto que a impressão em ficheiro está organizada para facilitar a leitura através de funções IO e criação de um novo ESTADO do programa.
  * @param state Apontador para o estado do programa;
 */

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