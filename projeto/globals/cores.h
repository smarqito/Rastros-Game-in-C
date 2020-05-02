//
// Created by marco on 3/22/20.
//

#ifndef RASTROS_CORES_H
#define RASTROS_CORES_H

#define COR_VERMELHO "\033[0;31m"
#define COR_VERMELHO_NEGRITO "\033[1;31m"
#define COR_AMARELO "\033[0;33m"
#define COR_AMARELO_NEGRITO "\033[1;33m"
#define COR_VERDE "\033[0;32m"
#define COR_VERDE_NEGRITO "\033[1;32m"
#define COR_AZUL "\033[0;34m"
#define COR__AZUL_NEGRITO "\033[1;034m"
#define COR_CIANO "\033[0;36m"
#define COR_CIANO_NEGRITO "\033[1;36m"
#define COR_ROXO "\033[0;35m"
#define NEGRITO_ON "\033[1m"
#define NEGRITO_OFF "\033[22m"
#define SUBLINHADO_ON "\033[4m"
#define SUBLINHADO_OFF "\033[24m"
#define RESET "\033[0m"

/**
 * @brief Formata a bash com a cor indicada
 * 
 * @param cor Macro definido neste documento!
 */
void promptFormata(char cor[]);
#endif //RASTROS_CORES_H
