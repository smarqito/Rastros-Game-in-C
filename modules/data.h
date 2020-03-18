/*
@file data.h
Definição do estado e das funções que o manipulam
 */

#ifndef RASTROS_DATA_H
#define RASTROS_DATA_H

#include "../globals/globals.h"

/*
\brief Tipo de dados para a casa
 */
typedef enum {VAZIO, BRANCA, PRETA,JOGADOR1,JOGADOR2} CASA;
/*
\brief Tipo de dados para definir se está a jogar contra um bot
 */
typedef enum {NO,YES} BOT;

/*
\brief Tipo de dados para as coordenadas
 */
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
CASA converteChar (int c);

int getNumberPlays (ESTADO *state);

int numero_comandos(ESTADO *state);
#endif //RASTROS_DATA_H
