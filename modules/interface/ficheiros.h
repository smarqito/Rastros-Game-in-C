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

/**
 * \brief
 * @param state Apontador para o estado do programa;
 */
void escreveHistorico (ESTADO *state);

/**
 * \brief
 * @param state Apontador para o estado do programa;
 */
void verificaHistorico(ESTADO *state);


/** @brief Imprime uma mensagem.
 * Imprime uma mensagem para gravar ou ler o Jogo, caso o Jogador queira;
 *
 * @param state Apontador para o estado do programa;
 * @param nomeFicheiro Ficheiro onde se vai gravar o Jogo;
 * @return
 */
int gravarJogo (ESTADO *state, char *nomeFicheiro);

/** @brief  Imprime números com dois dígitos.
 * Exemplo.: 1 = 01 ou 2 = 02 (Números com dois digitos ficam inalterados);
 * Usada na função 'imprimirJogadas' e 'gravarJogo';
 *
 * @param i Número da Jogada;
 * @param save Ficheiro;
 */
void numeros2Digitos (int i, FILE *save);

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
 * @param state Apontador para o estado do programa;
 * @param nome Ficheiro Ficheiro do qual se está a ler o programa;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int lerJogo (ESTADO *e, char *nomeFicheiro);



#endif //RASTROS_FICHEIROS_H
