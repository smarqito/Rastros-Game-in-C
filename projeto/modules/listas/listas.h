
/** @file
 * @brief Definição das funções da camada de listas do programa.
 */

#ifndef RASTROS_LISTAS_H
#define RASTROS_LISTAS_H

#include "../../globals/globals.h"
#include "../data.h"

/**
 * @brief Cria um novo espaço em memória capaz de albergar uma lista
 * 
 * @return o apontador para a nova lista
 */
LISTA criarLista ();

/**
 * @brief Insere numa nova lista um valor do tipo void
 * 
 * @param l Apontador para o início da lista
 * @param valor Apontador para um espaço em memória (sem tipo específico)
 * 
 * @return Apontador para o novo inicio da lista ligada
 */
LISTA insereCabeca (LISTA l, void *valor);

/**
 * @brief Vai buscar o apontador para o valor que se encontra na cabeça da lista
 * 
 * @param l Apontador para o início da lista
 * 
 * @return Apontador para o valor à cabeça
 */
void *devolveCabeca (LISTA l);

/**
 * @brief Vai buscar o próximo elemento da lista
 * 
 * @param l Apontador para o início da lista
 * 
 * @return Apontador para o Nodo seguinta da lista
 */
LISTA proximo (LISTA l);

/**
 * @brief Remove a cabeça da lista e liberta o seu espaço em memória
 * 
 * Para além de retornar o apontador para o Nodo seguinte, liberta o espaço em memória ocupado pela
 * cabeça através da função free.
 * @param l Apontador para o início da lista
 * 
 * @return Apontador para o nodo seguinte
 */
LISTA removeCabeca (LISTA l);

/**
 * @brief Verifica se uma dada lista é vazia
 * 
 * @param l Apontador para o início da lista
 * 
 * @return 0 se a lista for vazia. 1 se tive algum elemento.
 */
int listaEstaVazia (LISTA l);

/**
 * @brief Devolve o tamanho de uma lista ligada
 * 
 * @param lista Apontador para o inicio da lista
 * 
 * @return tamanho da lista
 */
int lengthLista (LISTA lista);

#endif //RASTROS_DATA_H
