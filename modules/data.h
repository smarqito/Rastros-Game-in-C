//
// Created by marco on 3/9/20.
//

#ifndef RASTROS_DATA_H
#define RASTROS_DATA_H

#include "../globals.h"

typedef enum {VAZIO, BRANCA, PRETA} CASA;

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
    int numJogadas;
    int jogadorAtual;
} ESTADO;

ESTADO *initState ();
#endif //RASTROS_DATA_H
