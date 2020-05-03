/**
 * @file
 * @brief Cores para a formatação
 */

#ifndef RASTROS_CORES_H
#define RASTROS_CORES_H

/**
 * @def COR_VERMELHO
 * @brief COR_VERMELHO
 */
#define COR_VERMELHO "\033[0;31m"

/**
 * @def COR_VERMELHO_NEGRITO
 * @brief COR_VERMELHO_NEGRITO
 */
#define COR_VERMELHO_NEGRITO "\033[1;31m"

/**
 * @def COR_AMARELO
 * @brief COR_AMARELO
 */
#define COR_AMARELO "\033[0;33m"

/**
 * @def COR_AMARELO_NEGRITO
 * @brief COR_AMARELO_NEGRITO
 */
#define COR_AMARELO_NEGRITO "\033[1;33m"

/**
 * @def COR_VERDE
 * @brief COR_VERDE
 */
#define COR_VERDE "\033[0;32m"

/**
 * @def COR_VERDE_NEGRITO
 * @brief COR_VERDE_NEGRITO
 */
#define COR_VERDE_NEGRITO "\033[1;32m"

/**
 * @def COR_AZUL
 * @brief COR_AZUL
 */
#define COR_AZUL "\033[0;34m"

/**
 * @def COR__AZUL_NEGRITO
 * @brief COR__AZUL_NEGRITO
 */
#define COR__AZUL_NEGRITO "\033[1;034m"

/**
 * @def COR_CIANO
 * @brief COR_CIANO
 */
#define COR_CIANO "\033[0;36m"

/**
 * @def COR_CIANO_NEGRITO
 * @brief COR_CIANO_NEGRITO
 */
#define COR_CIANO_NEGRITO "\033[1;36m"

/**
 * @def COR_ROXO
 * @brief COR_ROXO
 */
#define COR_ROXO "\033[0;35m"

/**
 * @def NEGRITO_ON
 * @brief NEGRITO_ON
 */
#define NEGRITO_ON "\033[1m"

/**
 * @def NEGRITO_OFF
 * @brief NEGRITO_OFF
 */
#define NEGRITO_OFF "\033[22m"

/**
 * @def SUBLINHADO_ON
 * @brief SUBLINHADO_ON
 */
#define SUBLINHADO_ON "\033[4m"

/**
 * @def SUBLINHADO_OFF
 * @brief SUBLINHADO_OFF
 */
#define SUBLINHADO_OFF "\033[24m"

/**
 * @def RESET
 * @brief RESET
 */
#define RESET "\033[0m"

/**
 * @brief Formata a bash com a cor indicada
 * 
 * @param cor Macro definido neste documento!
 */
void promptFormata(char cor[]);
#endif //RASTROS_CORES_H
