/** @file */

#ifndef RASTROS_AUXILIARESINTERFACE_H
#define RASTROS_AUXILIARESINTERFACE_H

/** 
 * @brief Imprime um número de apenas 1 dígito em dois, acresentando um zero atrás.
 *
 * Números de dois dígitos permancem inalterados.
 * Neste caso, imprime no terminal e não num ficheiro.
 *
 * @param i Número de jogadas a imprimir
 */
void digitosTerminal (int i);

/**
 * @brief Imprime a tabela de opções de comandos.
 */
void pedeAjuda();

/**
 * @brief Compara se a instrução recebida pertence ao grupo de instruções possíveis.
 *
 * @param instr instrução inserida pelo utilizador e que vai ser comparada;
 * @return 0 se não for possível. o índice + 1 caso a instrução exista;
 */
int instrucao (char *instr);

/**
 * @brief Imprime a informação sobre os autores deste projeto.
 */
void verAutores();

/**
 * @brief Função que permite gerir a saída do programa.
 * 
 * @return 0 se for para sair
 *         1 se for para voltar ao interpretador
 */
int confirmaSaida ();
#endif //RASTROS_AUXILIARESINTERFACE_H
