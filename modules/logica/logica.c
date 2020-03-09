//
// Created by marco on 3/9/20.
//

#include <stdio.h>
#include "logica.h"
#include "../data.h"

int isPossiblePlay1 (ESTADO *state, COORDENADA c){
    JOGADA ultima = state->jogadas[];
    int linhaU1 = ultima.jogador1.linha, colunaU1 = ultima.jogador1.coluna;
    int linhaA = c.linha, colunaA = c.coluna;
    int resposta = 0;
    if( linhaA == linhaU1 + 1 || linhaA == linhaU1 - 1 || linhaA == linhaU1){
        if (colunaA == colunaU1 + 1 || colunaA == colunaU1 - 1 || colunaA == colunaU1){
            resposta = 1;
        }
    }
    if (linhaA == linhaU1 && colunaA == colunaU1) resposta = 0;
    return resposta;
}

int isPossiblePlay2 (ESTADO *state, COORDENADA c){
    JOGADA ultima = state->jogadas[];
    int linhaU2 = ultima.jogador2.linha, colunaU2 = ultima.jogador2.coluna;
    int linhaA = c.linha, colunaA = c.coluna;
    int resposta = 0;
    if( linhaA == linhaU2 + 1 || linhaA == linhaU2 - 1 || linhaA == linhaU2){
        if (colunaA == colunaU2 + 1 || colunaA == colunaU2 - 1 || colunaA == colunaU2){
            resposta = 1;
        }
    }
    if (linhaA == linhaU2 && colunaA == colunaU2) resposta = 0;
    return resposta;
}

int isPossiblePlay (ESTADO *estado, COORDENADA c){
    int resposta;
    if()
}


int jogar (ESTADO *state, COORDENADA c){
    printf("jogar %d %d\n", c.coluna, c.linha);
    if (getHouseState(*state,c) == VAZIA && isPossiblePlay(*state, c)){

}