/**
 * @file
 * @brief Header main bot
 */

#ifndef RASTROS_BOT_H
#define RASTROS_BOT_H

#include "../projeto/modules/data.h"

/**
 * @brief Programa principal para a utilização do bot 
 *        (de forma externa ao programa principal)
 * 
 * @param argc Contador de número de argumentos recebidos na bash
 * @param argv Array multidimensional com as strings passadas na bash
 *             cada índice corresponde a um argumento
 * 
 * @return  0 sem erros
 *          1 Nome do ficheiro está errado
 *          2 Não há jogadas. Alguém já ganhou.
 */
int main (int argc, char *argv[]);
#endif //RASTROS_BOT_H
