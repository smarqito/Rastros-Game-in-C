/**
 * @file
 */

#ifndef _AUXILIARES_BOT_H
#define _AUXILIARES_BOT_H

#include "../projeto/modules/data.h"

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
 * @brief Utiliza uma lista criada para selecionar uma jogada aleatória
 * 
 * @param coordPossiveis Apontador para o inicio da lista de coord possíveis
 * @param jogada Endereço de um apontador para uma coordenada
 * 
 * @return 0 se não houver jogadas possíveis
 *         ~0 se selecionou uma jogada
 */
COORDENADA* botRandom (LISTA coordPossiveis);

/**
* @brief Calcula a distância euclidiana entre a coordenada dada e o destino
* O destino pode ser a casa do Jogador 1, ou 2
*
* @param c Apontador para uma coordenada da lista de coord possíveis
* @param jog int correspondente ao Jogador em questão
*
* @return Distância euclidiana resultante
*/
double calculaDist (COORDENADA *a, int numeroJog);

/**
* @brief Escolhe a melhor Jogada dependendo da distancia euclidiana
* De acordo com o Jogador atual, vai escolher a jogada que fica mais perto do seu destino
*
* @param state Apontador para o estado do programa
* @param c coordPossiveis Apontador para o inicio da lista de coord possíveis
* @param jogada Endereço de um apontador para uma coordenada
*
* @return 0 se não houver jogadas possíveis
*         ~0 se selecionou uma jogada
*/
COORDENADA *distanciaJog (ESTADO *state, LISTA coordPossiveis);

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
 * @brief Função para efetuar uma pesquisa ao longo de uma árvore
 *        até uma determinada profundidade
 * @param state Estado do programa
 * @param ll Apontador para uma lista de possíveis coordenadas
 * @param profundidade 
 * 
 * @return Coordenada ótima
 */
COORDENADA *treeSearch (ESTADO state, LISTA ll, int profundidade, int player);
#endif