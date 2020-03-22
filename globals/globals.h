/** @file
 *  @brief Definição de macros utilizados no programa.
 *
 */

#ifndef RASTROS_GLOBALS_H
#define RASTROS_GLOBALS_H

/**
 * @def Tamanho do buffering para o stdin.
 */
#define BUF_SIZE 1024

/**
 * @def Número de linhas/colunas do tabuleiro (lin = col)
 */
#define MAX_HOUSES 8

/**
 * @def Número de comandos possíveis de utilizar no interpretador.
 */
#define MAX_INSTR 9

#include "cores.h"

#define LOCAL_GRAVAR_FICHEIROS "./ficheirosGravados/"
#endif //RASTROS_GLOBALS_H
