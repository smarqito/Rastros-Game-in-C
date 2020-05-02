/** @file
 *  @brief Definição das função que permitem ao utilizador interagir com o programa.
 */

#ifndef RASTROS_INTERPRETADOR_H
#define RASTROS_INTERPRETADOR_H

#include "../data.h"
#include "../../globals/globals.h"

/**
 * @brief Entra em modo de 'jogar' até:
 *        Um jogador ganhar.
 *        O utilizador optar por voltar ao menú anterior.
 * 
 * @param e Apontador para o estado do programa
 * @param input Apontador para a struct input
 * 
 * @return 0 sem erros
 *         1 se o input não está correto
 */
int jogarRastros(ESTADO *e, INPUT *input);

/** @brief Imprime os Comandos.
 *
 * @param state Apontador para o estado do programa;
 */
void imprimeComandos (ESTADO *state);

/** 
 * @brief Dado um estado, um input e um comando vai executar a função adequada
 *
 * @param e Apontador para o estado do programa
 * @param input Apontador para struct com input
 * @param comando A ser executado
 * @return
 */
int comandos (ESTADO *e, INPUT *input, int comando);

/**
 * @brief Principal interpretador de comandos do programa.
 *
 * Permite ao utilizador interagir com o programa, utilizando os comandos descritos na função pedeAjuda.
 * @param e Apontador para o estado do programa.
 * @return 1 ou 0, caso ocorrer algum erro de leitura ou não, respetivamente;
 */
int interpretador (ESTADO *e);

#endif //RASTROS_INTERPRETADOR_H
