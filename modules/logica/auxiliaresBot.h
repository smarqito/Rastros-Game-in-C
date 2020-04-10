/**
 * @file
 */

#ifndef _AUXILIARES_BOT_H
#define _AUXILIARES_BOT_H

#include "../data.h"

/**
 * @brief Calcula o número de jogadas possíveis e quais as respetivas coordenadas
 * a partir coordenada da última jogada.
 * 
 * @param state Apontador para o estado do programa
 * @param cs Vetor unidimensional com 8 posições livres (máximo de jogadas possíveis).
 * Este vetor será preenchido com as coordenadas das jogadas possíveis
 * 
 * @return Número de jogadas possíveis
 * 
 */
LISTA coordenadasPossiveis (ESTADO *state);

/**
 * @brief Cria um apontador do tipo void para uma coordenada
 */
COORDENADA *criaCoordenada (COORDENADA c);

/**
 * @brief Efetua uma jogada construída pelo bot
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return 0 sem erros
 *         1 não foi possível jogar
 *         2 não há jogadas possíveis
 */
int jogaBot (ESTADO *state);


#endif