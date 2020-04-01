/** @file
 *  @brief Definição das função que permitem ao utilizador interagir com o programa.
 */

#ifndef RASTROS_INTERPRETADOR_H
#define RASTROS_INTERPRETADOR_H

#include "../data.h"
#include "../../globals/globals.h"

int jogarRastros(ESTADO *e, INPUT *input);

/** @brief Imprime os Comandos.
 *
 * @param state Apontador para o estado do programa;
 */
void imprimeComandos (ESTADO *state);

/** @brief
 *
 * @param e
 * @param input
 * @param comando
 * @return
 */
int comandos (ESTADO *e, INPUT *input, int comando);

/**
 * @brief Divide um determinado input em comando e argumento.
 *
 * @param input Linha de texto inserida pelo utilizador.
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int divideInput (INPUT *resposta, char *input);

/**
 * @brief Permite jogar rastros até:
 *        Um jogador ganhar.
 *        O utilizador optar por voltar ao menú anterior.
 * @param state Apontador para o estado do programa.
 * @return 1 ou 0, caso houver algum erro ou não, respetivamente;
 */
int jogarRastros (ESTADO *state, INPUT *input);

/**
 * @brief Principal interpretador de comandos do programa.
 *
 * Permite ao utilizador interagir com o programa, utilizando os comandos descritos na função pedeAjuda.
 * @param e Apontador para o estado do programa.
 * @return 1 ou 0, caso ocorrer algum erro de leitura ou não, respetivamente;
 */
int interpretador (ESTADO *e);

#endif //RASTROS_INTERPRETADOR_H
