/** @file */

#include <stdio.h>
#include "interface.h"
#include "../logica/logica.h"
#include "auxiliaresInterface.h"



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


int jogar (ESTADO *state, COORDENADA c){
    if (verificaCasa(state, c)){
        changeCardinal(state,c); /*! <Muda '*' e '#' */
        atualizaJogadas(state,c);
        atualizaMaxJogadas(state);
        mostrarTabuleiro(state);
        return 1;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 0;
    }
}


int lerMovimentos (ESTADO *state) {
    int i;
    int maxComandos;

    for(maxComandos=obterMaxComandos(state), i=0; maxComandos>0; i++) {
        if(maxComandos > 1) {
            digitosTerminal (i);
            printf("%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
            printf("%c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
            maxComandos=maxComandos-2;
        } else {
            digitosTerminal (i);
            printf("%c%c",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
                putchar('\n');
            maxComandos--;
        }
    }

    return 0;
}

