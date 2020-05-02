/** @file
 *  @brief Definição de macros utilizados no programa.
 *
 */

#ifndef RASTROS_GLOBALS_H
#define RASTROS_GLOBALS_H

/**
 * @def BUF_SIZE 
 * @brief   Tamanho do buffering para o stdin.
 */
#define BUF_SIZE 1024

/**
 * @def MAX_HOUSES 
 * @brief   Número de linhas/colunas do tabuleiro (lin = col)
 */
#define MAX_HOUSES 8

/**
 * @def MAX_INSTR 
 * @brief   Número de comandos possíveis de utilizar no interpretador.
 */
#define MAX_INSTR 13

#include "cores.h"

/**
 * @def LOCAL_GRAVAR_FICHEIROS  
 * @brief   Local utilizado para gravar os tabuleiros durante o programa
 *          Comandos ler e gr
 */
#define LOCAL_GRAVAR_FICHEIROS "./projeto/jogos/"

#endif //RASTROS_GLOBALS_H
