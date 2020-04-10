/** @file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logica.h"
#include "auxiliaresBot.h"
#include "../interface/interface.h"
#include "../../globals/globals.h"
#include "../data.h"
#include "../listas/listas.h"




void changeCardinal (ESTADO *state, COORDENADA c) {
    int m,n;
    m=state->ultimaJogada.linha; /*! <Linha da jogada */
    n=state->ultimaJogada.coluna; /*! <Coluna da jogada */
    state->tab[m][n] = PRETA; /*! <Jogada anterior -> '#' */
    state-> tab[c.linha][c.coluna] = BRANCA; /*! <Jogada atual -> '*' */
}


int verificaVizinhanca (ESTADO *state, COORDENADA c){
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



int verificaCasa (ESTADO *state, COORDENADA c){
    int resposta = 0;
    if ((obterEstadoCasa(state, c) == VAZIO
         || obterEstadoCasa(state, c) == JOGADOR1
         || obterEstadoCasa(state, c) == JOGADOR2)
        && verificaVizinhanca(state, c))
            resposta = 1;
    return resposta;
}

void atualizaMaxJogadas (ESTADO *state) {
    state->maxJogadas=obterNumeroJogadas(state);
    state->maxComandos=numeroComandos(state);
}

void atualizaJogadas (ESTADO *state, COORDENADA c) {
    if (!state->jogadorAtual) {
        state->jogadorAtual=1;
        state->jogadas[obterNumeroJogadas(state)].jogador1=c;
    } else {
        state->jogadorAtual=0;
        state->jogadas[state->numJogadas++].jogador2=c;
        // state->numJogadas++;
    }
    state->ultimaJogada=c;
    state->numComandos++;
}


char converteCasa (CASA house) {
    char casa;
    switch (house) {
        case VAZIO:
            casa = CASA_VAZIO;
            break;
        case BRANCA:
            promptFormata(COR_VERMELHO_NEGRITO);
            casa = CASA_BRANCA;
            break;
        case PRETA:
            promptFormata(COR_ROXO);
            casa = CASA_PRETA;
            break;
        case JOGADOR1:
            promptFormata(COR_AMARELO_NEGRITO);
            casa = CASA_JOGADOR1;
            break;
        case JOGADOR2:
            promptFormata(COR_AMARELO_NEGRITO);
            casa = CASA_JOGADOR2;
            break;
        default:
            casa='0';
            break;
    }
    return casa;
}



int verificaFim (ESTADO *state) {
    if(state->tab[MAX_HOUSES-1][MAX_HOUSES-1] == BRANCA)
        return 2;
    else if (state->tab[0][0]==BRANCA)
        return 1;
    else if (!verificaPossibilidades(state))
        return (obterJogador(state) == 1) ? 2 : 1 ;
    else
        return 0;;
}




int converteDecimal (const char *jogada) {
    int x=0;
    x += (jogada[0]-'0') * 10;
    x += (jogada[1]-'0');
    return x;
}

int removeCarateresExtra (char *s) {
    int i=0,n;
    while(s[i]) {
        if(s[i] == ':') {
            n=i;
            while(s[n]) {
                s[n] = s[n+1];
                n++;
            }
        }
        i++;
    }
    return 0;
}


int atualizaCoordenadaJogada (ESTADO *state, COORDENADA *c, int jogador) {
    int numJogada = state->numJogadas;
    if(jogador == 1) {
        state->jogadas[numJogada].jogador1.coluna=c->coluna;
        state->jogadas[numJogada].jogador1.linha=c->linha;
    } else {
        state->jogadas[numJogada].jogador2.coluna=c->coluna;
        state->jogadas[numJogada].jogador2.linha=c->linha;
    }
    return 0;
}

void posAux (ESTADO *state, COORDENADA c){
    changeCardinal(state, c);
    atualizaJogadas(state, c);
}

void mostraPos( ESTADO *state, char *pos) {
    int i;
    int c = atoi(pos), numeroJogadas; //! Número de jogadas que se pretende imprimir;
    numeroJogadas = obterMaxJogadas(state) + 1;

    if (c > numeroJogadas || c < 0) {
        if (c == 0) 
            printf("Encontra-se na posição inicial. Não há jogadas anteriores.\n");
        else 
            printf("O intervalo de posições é de %d até %d\n", 0, numeroJogadas );
    } else {
        initBoard(state);
        initPlay(state);
        initPlayer(state);
        if (c > 0) {
            for(i = 0; i < c; i++ ){
                COORDENADA jog1 = state->jogadas[i].jogador1;
                COORDENADA jog2 = state->jogadas[i].jogador2;
                posAux(state,jog1);
                if( (jog2.linha || jog2.coluna) || verificaFim(state) == 2 ) {
                    posAux(state, jog2);
                }
            }
        }
        mostrarTabuleiro(state);
    }

}

int verificaPossibilidades (ESTADO *state) {
    int r=0;
    LISTA l;
    
    l=coordenadasPossiveis(state);
    r=lengthLista(l);

    return r;
}