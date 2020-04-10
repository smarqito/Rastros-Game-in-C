#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "auxiliaresBot.h"
#include "../data.h"
#include "../listas/listas.h"
#include "logica.h"
#include "../interface/interface.h"

LISTA coordenadasPossiveis (ESTADO *state) {
    int m,n;
    COORDENADA c;
    LISTA ll = NULL;
    m=state->ultimaJogada.linha;
    m = (m == 0) ? m : (m-1);

    for(; m<MAX_HOUSES && m<=(state->ultimaJogada.linha+1); m++) {
        for(n=(state->ultimaJogada.coluna==0) ? 0 : (state->ultimaJogada.coluna-1); n<MAX_HOUSES && n<=(state->ultimaJogada.coluna+1); n++) {
            c.linha = m;
            c.coluna = n;
            if(verificaCasa(state,c)) {
                ll=insereCabeca(ll, criaCoordenada(c));
            }

        }
    }

    return ll;
}

COORDENADA *criaCoordenada (COORDENADA c) {
    COORDENADA *novo = (COORDENADA *) malloc (sizeof(COORDENADA));
    
    novo->coluna=c.coluna;
    novo->linha=c.linha;

    return novo;
}

int jogaBot (ESTADO *state) {
    int r,i;
    srand(time(0));

    LISTA l = coordenadasPossiveis(state);
    COORDENADA *jogadaBot;
    r = lengthLista(l);
    if(r>0) {
        for(i = rand() % r; i>0; i--){
            proximo(l);
        }
        jogadaBot=devolveCabeca(l);

        r = jogar(state,*jogadaBot);
    }
    else r = 2;
    

    return r;
}