/** @file */
#include <stdlib.h>
#include "data.h"


void initBoard (ESTADO *state) {
    int m,n;
    for(m=MAX_HOUSES-1;m>=0;m--)
        for(n=0;n<MAX_HOUSES;n++)
            state->tab[m][n] = VAZIO;
    state->tab[4][4] = BRANCA;
    state->tab[7][7] = JOGADOR2;
    state->tab[0][0] = JOGADOR1;
}

void initPlay (ESTADO *state) {
    state->ultimaJogada.linha=4;
    state->ultimaJogada.coluna=4;
}


void initPlayer (ESTADO *state) {
    state -> numJogadas = 0;
    state -> jogadorAtual = 0;
    state -> numComandos = 0;
    state->bot=NO;
    state->nivel=0;
}


ESTADO *initState() {
    ESTADO *newState = (ESTADO *) malloc(sizeof(ESTADO));
    initBoard(newState);
    initPlay(newState);
    initPlayer(newState);
    newState->maxComandos=0;
    return newState;
}

int obterJogador (ESTADO *state) {
    return state->jogadorAtual + 1;
}


CASA obterEstadoCasa (ESTADO *state, COORDENADA c){
    return state->tab[c.linha][c.coluna];
}


int obterNumeroJogadas (ESTADO *state){
    return state->numJogadas;
}

int obterMaxJogadas (ESTADO *state) {
    return state->maxJogadas;
}


int numeroComandos (ESTADO *state) {
    // if (!state->jogadorAtual)
    //     return (state ->numJogadas*2)+1;
    // else
    //     return (state -> numJogadas*2)+2;
    return state->numComandos;
}

int obterMaxComandos (ESTADO *state) {
    return state->maxComandos;
}

CASA converteChar (int c) {
    switch (c) {
        case CASA_BRANCA:
            return BRANCA;
        case CASA_PRETA:
            return PRETA;
        case CASA_VAZIO:
            return VAZIO;
        case CASA_JOGADOR1:
            return JOGADOR1;
        case CASA_JOGADOR2:
            return JOGADOR2;
        default:
            return CASA_PRETA;
    }
}

int podeJogar (CASA casa) {
    return (casa == BRANCA) ? 1 : 0;
}