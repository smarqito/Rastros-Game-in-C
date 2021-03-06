/** 
 * @file
 * @brief Camada de dados
 */
#include <stdlib.h>
#include <string.h>
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

COORDENADA *obterUltimaJogada (ESTADO *state) {
    COORDENADA *ultimaJog = (COORDENADA*) malloc(sizeof(COORDENADA));

    ultimaJog->coluna=state->ultimaJogada.coluna;
    ultimaJog->linha=state->ultimaJogada.linha;
    
    return ultimaJog;
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

INPUT *initInput() {
    INPUT *novoInput = (INPUT *) malloc (sizeof(INPUT));

    novoInput->comando=(char*) calloc(10,sizeof(char));
    novoInput->argumento=(char*) calloc(10,sizeof(char));

    return novoInput;
}

int obterNivelBot(ESTADO *state) {
    return state->nivel;
}

void alteraEstadoBot(ESTADO *state) {
    state->bot=!(state->bot);
}

void alteraNivelBot(ESTADO *state, int nivel) {
    state->nivel=nivel;
}

int lerEstadoBot(ESTADO *state) {
    return state->bot;
}

char obterLinhaColuna (ESTADO *state, int jogador, int jogada, char tipo) {
    char r = 0;
    if(tipo == 'c') {
        if(jogador == 1) {
            r = state->jogadas[jogada].jogador1.coluna +'a';
        } else {
            r = state->jogadas[jogada].jogador2.coluna +'a';
        }
    } else if (tipo == 'l') {
        if(jogador == 1) {
            r = state->jogadas[jogada].jogador1.linha + '1';
        } else {
            r = state->jogadas[jogada].jogador2.linha + '1';
        }
    }
    return r;
}

char *obterArgumentoComando (INPUT *input, int escolha ){
    return ((escolha) ? input->argumento : input->comando);
}

