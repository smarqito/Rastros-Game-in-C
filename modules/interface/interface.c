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
            COORDENADA c;
            c.coluna = n; c.linha = m;
            printf("%c" COR_AZUL " | ", converteCasa(obterEstadoCasa(state,c))); // imprime a casa na linha de comandos
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
        
        return 0;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 1;
    }
}


int lerMovimentos (ESTADO *state) {
    int i;
    int maxComandos;

    for(maxComandos=obterMaxComandos(state), i=0; maxComandos>0; i++) {
        if(maxComandos > 1) {
            digitosTerminal (i);
            printf("%c%c ",obterLinhaColuna(state,1,i,'c'),obterLinhaColuna(state,1,i,'l'));
            printf("%c%c\n",obterLinhaColuna(state,2,i,'c'),obterLinhaColuna(state,2,i,'l'));
            maxComandos=maxComandos-2;
        } else {
            digitosTerminal (i);
            printf("%c%c",obterLinhaColuna(state,1,i,'c'),obterLinhaColuna(state,1,i,'l'));
                putchar('\n');
            maxComandos--;
        }
    }

    return 0;
}

