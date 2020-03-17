//
// Created by marco on 3/9/20.
//
#include <stdlib.h>
#include "data.h"

void initBoard (ESTADO *state)
{
    int m,n;
    for(m=MAX_HOUSES-1;m>=0;m--)
        for(n=0;n<MAX_HOUSES;n++)
            state->tab[m][n] = VAZIO;
    state->tab[3][4] = BRANCA;
    state->tab[7][7] = JOGADOR2;
    state->tab[0][0] = JOGADOR1;
}

void initPlay (ESTADO *state) {
    state->ultimaJogada.linha=3;
    state->ultimaJogada.coluna=4;
}

void initPlayer (ESTADO *state) {
    state -> numJogadas = 0;
    state -> jogadorAtual = 0;
    state->bot=NO;
    state->nivel=0;
}

ESTADO *initState() {
    ESTADO *newState = (ESTADO *) malloc(sizeof(ESTADO));
    initBoard(newState);
    initPlay(newState);
    initPlayer(newState);
    return newState;
}

int getPlayer (ESTADO *state) {
    return state->jogadorAtual + 1;
}

CASA getHouseState (ESTADO *state, COORDENADA c){
    return state->tab[c.linha][c.coluna];
}

int getNumberPlays (ESTADO *state){
    return state->numJogadas;
}

int numero_comandos (ESTADO *state) {
    if (!state->jogadorAtual)
        return (state ->numJogadas*2)+1;
    else
        return (state -> numJogadas*2)+2;
}