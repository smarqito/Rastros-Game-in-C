/** @file
 * @brief Atualmente este ficheiro não está a ser utilizado. Serve para referência futura e reorganização do código.
 */

#ifndef RASTROS_FICHEIROS_H
#define RASTROS_FICHEIROS_H

#include <bits/types/FILE.h>
#include "../data.h"


/**
 * @brief Remove o primeiro \n que encontra e termina a string.
 * @param string Array que vai ser processada.
 */
void removerLinha (char *string);

/** @brief Imprime uma mensagem.
 * Imprime uma mensagem para gravar ou ler o Jogo, caso o Jogador queira;
 *
 * @param state Apontador para o estado do programa;
 * @param nomeFicheiro Ficheiro onde se vai gravar o Jogo;
 * @return 0 sem erros
 *         1 Não foi possível gravar o ficheiro
 */
int gravarJogo (ESTADO *state, char *nomeFicheiro);

/** @brief Imprime as Jogadas efetuadas (abaixo do tabuleiro).
 * Usada na função 'gravarJogo';
 *
 * @param state Apontador para o estado do programa;
 * @param i Número da Jogada;
 * @param save Ficheiro;
 */
void imprimirJogadas (ESTADO *state, int i, FILE *save);

/**
 * @brief Lê uma linha do histórico de jogo do ficheiro
 * e insere-o no estado.
 * 
 * @param state Apontador para o estado do programa
 * @param cadaToken Apontador para a array lida no ficheiro
 * 
 * @return 0 caso cada token tenha 8 ou 5 de length. 
 *         1 caso contrário.
 */
int lerJogada (ESTADO *state, char *cadaToken);

/** 
 * @brief: Lê o jogo.
 *
 * Acede ao ficheiro inserido pelo utilizador e atualiza o estado do jogo;
 * 
 * @param e Apontador para o estado do programa;
 * @param nomeFicheiro Ficheiro Ficheiro do qual se está a ler o programa;
 * @return 0 sem erros
 *         1 não foi possível alocar memória/ ficheiro não encontrado
 *         2 ficheiro de origem mal construído
 */
int lerJogo (ESTADO *e, char *nomeFicheiro);



#endif //RASTROS_FICHEIROS_H
