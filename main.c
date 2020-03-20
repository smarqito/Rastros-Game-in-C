/** @file
 *  @brief Ficheiro de entrada no programa.
 */
#include "modules/data.h"
#include "modules/interface/interpretador.h"

/**
 * @brief Função de entrada no programa.
 * @return 0 se não houvve erros.
 */
int main() {
    ESTADO *e = initState();
    interpretador(e);
    return 0;
}