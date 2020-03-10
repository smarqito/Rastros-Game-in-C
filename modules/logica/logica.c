//
// Created by marco on 3/9/20.
//

#include <stdio.h>
#include "logica.h"

void changeCardinal (ESTADO *state) {
    int m,n;
    m=state->ultimaJogada.linha;
    n=state->ultimaJogada.coluna;
    state->tab[m][n] = PRETA;
}

int isPossiblePlay (ESTADO *state, COORDENADA c){
    COORDENADA ultima = state->ultimaJogada;
    int linhaU = ultima.linha, colunaU = ultima.coluna;
    int linhaA = c.linha, colunaA = c.coluna;
    int resposta = 0;
    if( linhaA == linhaU + 1 || linhaA == linhaU - 1 || linhaA == linhaU){
        if (colunaA == colunaU + 1 || colunaA == colunaU - 1 || colunaA == colunaU){
            resposta = 1;
        }
    }
    if (linhaA == linhaU && colunaA == colunaU) resposta = 0;
    return resposta;
}

int jogar (ESTADO *state, COORDENADA c){
    int jogadaP = 0;
    if ((getHouseState(state,c) == VAZIO || getHouseState(state,c) == JOGADOR1 || getHouseState(state,c) == JOGADOR2) && isPossiblePlay(state, c)){
        state-> tab[c.linha][c.coluna] = BRANCA;
        changeCardinal(state);
        state->ultimaJogada = c;
        return 1;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 0;
    }
}