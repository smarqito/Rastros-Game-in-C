/**
 * @file
 * @brief Header para as auxiliares
 */

#ifndef _AUXILIARES_BOT_H
#define _AUXILIARES_BOT_H

#include "../projeto/modules/data.h"

/**
 * @brief Calcula uma lista ligada de coordenadas possíveis a jogar
 *        a partir coordenada da última jogada.
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return Lista ligada com as possíveis coordenadas
 */
LISTA coordenadasPossiveis (ESTADO *state);

/**
 * @brief Cria um apontador do tipo void para uma coordenada
 * 
 * @param c Struct coordenada
 * 
 * @return Apontador alocado com malloc para uma struct COORDENADA
 */
COORDENADA *criaCoordenada (COORDENADA c);

/**
 * @brief Utiliza uma lista criada para selecionar uma jogada aleatória
 * 
 * @param coordPossiveis Apontador para o inicio da lista de coord possíveis
 * 
 * @return NULL se não houver jogadas possíveis
 *         uma COORDENADA se selecionou uma jogada
 */
COORDENADA* botRandom (LISTA coordPossiveis);

/**
* @brief Calcula a distância euclidiana entre a coordenada dada e o destino
*        O destino pode ser a casa do Jogador 1, ou 2
*
* @param a Apontador para uma coordenada da lista de coord possíveis
* @param numeroJog int correspondente ao Jogador em questão
*
* @return Distância euclidiana resultante
*/
double calculaDist (COORDENADA *a, int numeroJog);

/**
* @brief Escolhe a melhor Jogada dependendo da distancia euclidiana
*        De acordo com o Jogador atual, vai escolher a jogada que fica mais perto do seu destino
*
* @param state Apontador para o estado do programa
* @param coordPossiveis coordPossiveis Apontador para o inicio da lista de coord possíveis
*
* @return 0 se não houver jogadas possíveis
*         ~0 se selecionou uma jogada
*/
COORDENADA *distanciaJog (ESTADO *state, LISTA coordPossiveis);

/**
 * @brief Devolve e melhor jogada
 * @param ll Apontador para a lista ligada
 * @param jog Jogador a efetuar jogada
 * @return Um apontador para a melhor coordenada
 */
COORDENADA *besttLL (LISTA ll, int jog);
/**
 * @brief Função para efetuar uma pesquisa ao longo de uma árvore
 *        até uma determinada profundidade
 * @param state Estado do programa
 * @param ll Apontador para uma lista de possíveis coordenadas
 * @param profundidade 
 * @param player 1 para maximizar resultado
 *               -1 para minimizar resultado
 * 
 * @return Coordenada ótima
 */
COORDENADA *treeSearch (ESTADO state, LISTA ll, int profundidade, int player);

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

/**
 * @brief Efetua uma jogada e retorna o estado alterado
 * 
 * @param state Estado
 * @param c Void que contem uma coordenada
 * @return Novo estado
 */
ESTADO novoEstado (ESTADO state, void *c);
#endif