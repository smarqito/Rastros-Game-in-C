/**
 * @file
 * @brief Funções com a funcionalidade do bot
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

#include "auxiliaresBot.h"
#include "../projeto/modules/data.h"
#include "../projeto/modules/listas/listas.h"
#include "../projeto/modules/logica/logica.h"
#include "../projeto/modules/interface/interface.h"

LISTA coordenadasPossiveis (ESTADO *state) {
    int m,n;
    COORDENADA c, *ultJogada;
    LISTA ll = NULL;
    ultJogada = obterUltimaJogada(state);
    m=ultJogada->linha;
    m = (m == 0) ? m : (m-1);

    for(; m<MAX_HOUSES && m<=(ultJogada->linha+1); m++) {
        for(n=(ultJogada->coluna==0) ? 0 : (ultJogada->coluna-1); n<MAX_HOUSES && n<=(ultJogada->coluna+1); n++) {
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

COORDENADA *botRandom (LISTA coordPossiveis) {
    int r,i;
    COORDENADA *jogada = NULL;

    r = lengthLista(coordPossiveis);

    if(r>0) {
        for(i = (rand() % r); i>0; i--){
            proximo(coordPossiveis);
        }
        jogada=devolveCabeca(coordPossiveis);
    }

    return jogada;
}


double calculaDist (COORDENADA *a, int numeroJog){
    int linhaA = a->linha, colunaA = a->coluna;
    int linhaB, colunaB;
    int distancia, distanciaB;
    double distanciaFinal;
    if (numeroJog == 1){
        linhaB = 0; colunaB = 0;
    } else {
        linhaB = 7; colunaB = 7;
    }
    distancia = linhaA - linhaB;
    distancia *= distancia;
    distanciaB = colunaA - colunaB;
    distanciaB *= distanciaB;
    distancia += distanciaB;
    distanciaFinal = sqrt(distancia);

    return distanciaFinal;
}


COORDENADA *distanciaJog (ESTADO *state, LISTA coordPossiveis) {
    double distancia, distanciaMenor = INT_MAX;
    LISTA r;
    COORDENADA *resposta = NULL;
    for (r = coordPossiveis; r; r = r->proxima) {
        distancia = calculaDist(r->valor, obterJogador(state));
        if (distancia < distanciaMenor) {
            resposta = r->valor;
            distanciaMenor=distancia;
        }
    }

    return resposta;
}

ESTADO novoEstado (ESTADO state, void *c) {
    COORDENADA *d = c;
    jogar(&state,*d);
    return state;
}

COORDENADA *bestLL (LISTA ll, int jog) {
    COORDENADA *best=NULL;
    float bestD = INT_MIN;
    for(; ll; ll=ll->proxima)
        if(calculaDist(ll->valor, jog) < bestD)
            best = ll->valor;
    return best;
}

COORDENADA *treeSearch (ESTADO state, LISTA ll, int profundidade, int player) {
    COORDENADA *jogada=NULL, *otima=NULL, *temp = NULL;
    int jog;
    if (verificaFim(&state)) {
        if(player == 1) {
            return jogada;
        } else {
            jogada = malloc(sizeof(COORDENADA));
            *jogada = state.ultimaJogada;
            return jogada;
        }
    } else if(profundidade == 0) {
            return bestLL(ll, obterJogador(&state));
    } else {
        while(ll) {
            ESTADO tree = novoEstado(state, ll->valor); // estado do jogo na minha jogada seguinte
            LISTA llSearch = coordenadasPossiveis(&tree);
            COORDENADA *novo = ll->valor;
            temp = treeSearch(tree, llSearch, profundidade-1, player*-1);
            jog = obterJogador(&tree);
            if ( player == 1 ) { // temp mais longe possivel
                if (!temp) { // se o temp for nulo pode ser: cheguei ao fim da arvore; não tem jogadas; alguem chegou ao fim
                    if(!otima) {
                        otima = novo;
                        jogada = novo;
                    }
                    else if( calculaDist(otima, jog) > calculaDist(novo, jog)) {
                        otima = novo;
                        jogada = novo;
                    }
                } else { // 
                    if(otima && calculaDist(otima, jog) < calculaDist(temp, jog)) { //maximizar o temp (adversário)
                        otima = temp;
                        jogada = novo;
                    }
                    else if (!otima) {
                        otima = temp;
                        jogada = novo;
                    }
                }
            } else if (player == -1) { // fica com a coordenada mais longe do destino
                if(temp && otima && calculaDist(otima, jog) > calculaDist(temp, jog) ) {
                    otima = temp;
                    jogada = novo;
                }
                else if (temp && !otima) {
                    otima = temp;
                    jogada = novo;
                }
            }
            ll = ll->proxima;
        }
    }
    
    return jogada;
}

int jogaBot (ESTADO *state) {
    int r=0;
    
    srand(time(0));

    LISTA l = coordenadasPossiveis(state);
    COORDENADA *jogadaBot=NULL;

    switch (obterNivelBot(state)) { //!< Nível de dificuldade do bot
        case 1:
            jogadaBot = distanciaJog(state,l);
            break;
        case 2:
            jogadaBot = treeSearch(*state, l, 1, 1);
            break;
        case 3:
            jogadaBot = treeSearch(*state, l, 3, 1);
            break;
        case 4:
            jogadaBot = treeSearch(*state, l, 5, 1);
            break;
        case 5:
            jogadaBot = treeSearch(*state, l, 7, 1);
            break;
        default:
            jogadaBot = botRandom(l);
            break;
    }

    if(jogadaBot) {
        r = jogar(state,*jogadaBot);
    } else {
        r=2;
    }

    free(l);
    free(jogadaBot);

    return r;
}