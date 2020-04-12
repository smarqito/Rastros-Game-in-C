#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "auxiliaresBot.h"
#include "../data.h"
#include "../listas/listas.h"
#include "logica.h"
#include "../interface/interface.h"

LISTA coordenadasPossiveis (ESTADO *state) {
    int m,n;
    COORDENADA c;
    LISTA ll = NULL;
    m=state->ultimaJogada.linha;
    m = (m == 0) ? m : (m-1);

    for(; m<MAX_HOUSES && m<=(state->ultimaJogada.linha+1); m++) {
        for(n=(state->ultimaJogada.coluna==0) ? 0 : (state->ultimaJogada.coluna-1); n<MAX_HOUSES && n<=(state->ultimaJogada.coluna+1); n++) {
            c.linha = m;
            c.coluna = n;
            if(verificaCasa(state,c)) {
                ll=insereCabeca(ll, criaCoordenada(c));
            }

        }
    }

    return ll;
}

COORDENADA *criaCoordenada (COORDENADA c) {
    COORDENADA *novo = (COORDENADA *) malloc (sizeof(COORDENADA));
    
    novo->coluna=c.coluna;
    novo->linha=c.linha;

    return novo;
}

int botRandom (LISTA coordPossiveis, COORDENADA **jogada) {
    int r,i;

    r = lengthLista(coordPossiveis);

    if(r>0) {
        for(i = (rand() % r); i>0; i--){
            proximo(coordPossiveis);
        }
        (*jogada)=devolveCabeca(coordPossiveis);
    }

    return r;
}


double calculaDist (COORDENADA *a, COORDENADA b){
    int linhaA = a->linha, colunaA = a->coluna;
    int linhaB = b.linha, colunaB = b.coluna;
    int distancia, distanciaB;
    double distanciaFinal;
    distancia = linhaA - linhaB;
    distancia *= distancia;
    distanciaB = colunaA - colunaB;
    distanciaB *= distanciaB;
    distancia += distanciaB;
    distanciaFinal = sqrt(distancia);
    

    return distanciaFinal;
}


int distanciaJog (ESTADO *state, LISTA coordPossiveis, COORDENADA **jogada) {
    double distancia, distanciaMenor = 50;
    int tamanho = lengthLista(coordPossiveis);
    LISTA r;
    COORDENADA *resposta = NULL, Jogador1, Jogador2;
    Jogador1.linha = 1;
    Jogador1.coluna = 1;
    Jogador2.linha = 8;
    Jogador2.coluna = 8;
    if (tamanho > 0) {
        if (obterJogador(state) == 1) {
            for (r = coordPossiveis; r; r = r->proxima) {
                distancia = calculaDist(r->valor, Jogador1);
                if (distancia < distanciaMenor) {
                    resposta = r->valor;
                    distanciaMenor=distancia;
                }
            }
        } else {
            for (r = coordPossiveis; r; r = r->proxima) {
                distancia = calculaDist(r->valor, Jogador2);
                if (distancia < distanciaMenor)  {
                    resposta = r->valor;
                    distanciaMenor=distancia;
                }
            }

        }
        (*jogada) = resposta;
    }

    return tamanho;
}


int jogaBot (ESTADO *state) {
    int r;
    srand(time(0));

    LISTA l = coordenadasPossiveis(state);
    COORDENADA *jogadaBot = (COORDENADA*) calloc(1,sizeof(COORDENADA));

    switch (state->nivel) {
        case 0:
            r = botRandom(l,&jogadaBot);
            break;
        case 1:
            r = distanciaJog(state,l,&jogadaBot);
            break;
        default:
            r = botRandom(l,&jogadaBot);
            break;
    }

    if(r>0) {
        if((r = jogar(state,*jogadaBot))) { //!< a função jogar retorna 1 se for sucesso, ao contrário do que acontece na jogaBot
            r=0;
        } 
        else r=1;
    }

    free(l);
    free(jogadaBot);

    return r;
}