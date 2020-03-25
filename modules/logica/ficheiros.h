/** @file
 * @brief Atualmente este ficheiro não está a ser utilizado. Serve para referência futura e reorganização do código.
 */

#ifndef RASTROS_FICHEIROS_H
#define RASTROS_FICHEIROS_H

#include "../data.h"


/**
 * @brief Remove o primeiro \n que encontra e termina a string.
 * @param string Array que vai ser processada.
 */
void removerLinha (char *string);

/**
 * \brief
 * @param state Apontador para o estado do programa;
 */
void escreveHistorico (ESTADO *state);

/**
 * \brief
 * @param state Apontador para o estado do programa;
 */
void verificaHistorico(ESTADO *state);

#endif //RASTROS_FICHEIROS_H
