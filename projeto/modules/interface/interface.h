/** @file
 *  @brief Definição das função da camada de interface do programa.
 *
 */

#ifndef RASTROS_INTERFACE_H
#define RASTROS_INTERFACE_H

#include "../data.h"
#include "../../globals/globals.h"

/** @brief Mostra o tabuleiro.
  *
  *  Imprime o tabuleiro em dois locais: (1) Na linha de comandos (2) Num ficheiro temporário (de texto);
  *
  *  Método:
  *  1. Declara-se um apontador do tipo FILE;
  *  2. Abre-se o ficheiro (Através da função fopen);
  *  3. Imprime-se o tabuleiro na linha de comandos (printf) e no ficheiro de texto (fprintf) (uma única passagem pela array tab);
  *      3.1. Utiliza-se a função converteCasa para, tal como o nome indica, converter uma CASA para um char.
  *  4. Fecha-se o ficheiro (fclose).
  *
  *  A impressão na linha de comandos encontra-se formatada para uma melhor leitura humana, enquanto que a impressão em ficheiro está organizada para facilitar a leitura através de funções IO e criação de um novo ESTADO do programa.
  * @param state Apontador para o estado do programa;
 */
void mostrarTabuleiro (ESTADO *state);



/** @brief Efetua (se possível) uma jogada.
 * Após verificar a condição (Função -> verificaCasa) modifica o ESTADO CASA (Para BRANCA);
 * Substitui no Tabuleiro o '*' por um '#' (Função -> changeCardinal);
 * Atualiza a última jogada;
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @return 1 ou 0, caso a jogada seja possível ou não, respetivamente;
 */
int jogar (ESTADO *state, COORDENADA c);



/** @brief Lê movimentos. Função aplicada no comando movs.
 *
 * @param e Apontador para o estado do programa.
 * @return 0 caso seja possível efetuar este comando.
 */
int lerMovimentos (ESTADO *e);



#endif //RASTROS_INTERFACE_H
