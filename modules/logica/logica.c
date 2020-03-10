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

int verificaFim (ESTADO *state) {
    if(state->tab[0][MAX_HOUSES-1] == BRANCA)
        return 2;
    else if (state->tab[MAX_HOUSES-1][0]==BRANCA)
        return 1;
    else
        return 0;;
}