//
// Created by marco on 3/9/20.
//

#ifndef RASTROS_DATA_H
#define RASTROS_DATA_H

#include "../globals/globals.h"

typedef enum {VAZIO, BRANCA, PRETA,JOGADOR1,JOGADOR2} CASA;

typedef enum {NO,YES} BOT;

typedef struct {
    int linha, coluna;
} COORDENADA;

typedef struct {
    COORDENADA jogador1, jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[MAX_HOUSES][MAX_HOUSES];
    COORDENADA ultimaJogada;
    JOGADAS jogadas;
    BOT bot;
    int numJogadas;
    int jogadorAtual;
    int nivel;
} ESTADO;

ESTADO *initState ();

int getPlayer (ESTADO *state);

CASA getHouseState(ESTADO *state, COORDENADA c);

int getNumberPlays (ESTADO *state);
#endif //RASTROS_DATA_H
