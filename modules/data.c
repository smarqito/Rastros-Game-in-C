/** @file
 * @brief Definição das função da camada de dados do programa.
 */
#include <stdlib.h>
#include "data.h"

/**
 * \brief Inicializa o tabuleiro.
 *
 * @param state Apontador para o estado do programa;
 */
void initBoard (ESTADO *state)
{
    int m,n;
    for(m=MAX_HOUSES-1;m>=0;m--)
        for(n=0;n<MAX_HOUSES;n++)
            state->tab[m][n] = VAZIO;
    state->tab[4][4] = BRANCA;
    state->tab[7][7] = JOGADOR2;
    state->tab[0][0] = JOGADOR1;
}

/**
 * \brief Inicializa o jogo na posição e5.
 *
 * @param state Apontador para o estado do programa;
 */
void initPlay (ESTADO *state) {
    state->ultimaJogada.linha=4;
    state->ultimaJogada.coluna=4;
}

/**
 * \brief Inicializa o programa com o Jogador 1 e 0 jogadas;
 *
 * @param state Apontador para o estado do programa;
 */
void initPlayer (ESTADO *state) {
    state -> numJogadas = 0;
    state -> jogadorAtual = 0;
    state->bot=NO;
    state->nivel=0;
}

/**
 * \brief Cria o Estado.
 *
 * @return Apontador do estado criado;
 */
ESTADO *initState() {
    ESTADO *newState = (ESTADO *) malloc(sizeof(ESTADO));
    initBoard(newState);
    initPlay(newState);
    initPlayer(newState);
    return newState;
}

/**
 * \brief Busca o jogador que está a jogar.
 *
 * @param state Apontador para o estado do programa;
 * @return Retorna o Jogador atual;
 */
int obterJogador (ESTADO *state) {
    return state->jogadorAtual + 1;
}

/**
 * \brief Encontra a CASA da coordenada dada.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @return Retorna a CASA em questão;
 */
CASA obterEstadoCasa (ESTADO *state, COORDENADA c){
    return state->tab[c.linha][c.coluna];
}

/**
 * \brief Obtém o número de jogadas;
 *
 * @param state Apontador para o estado do programa;
 * @return Número de jogadas;
 */
int obterNumeroJogadas (ESTADO *state){
    return state->numJogadas;
}

/**
 * @brief Conta o número de comandos.
 *
 * @param state Apontador para o estado do programa;
 * @return Multiplica por 2 e soma 1 no caso do Jogador 1 ou multiplica por 2 e soma 2 no caso do Jogador 2, ambos os casos através do número de jogadas;
 */
int numeroComandos (ESTADO *state) {
    if (!state->jogadorAtual)
        return (state ->numJogadas*2)+1;
    else
        return (state -> numJogadas*2)+2;
}

/** @brief Converte um caractér para CASA.
 *
 * @param c Caractér associado à casa;
 * @return Retorna a CASA em questão;
 */
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
    }
}

/** @brief Verifica sse pode jogar naquela CASA.
 *
 * @param casa Casa que pretendemos jogar;
 * @return 1 ou 0, caso seja possível jogar ou não, respetivamente;
 */
int podeJogar (CASA casa) {
    return (casa == BRANCA) ? 1 : 0;
}
