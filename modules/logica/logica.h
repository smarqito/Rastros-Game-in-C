/** @file
 * @brief Definição das função da camada de lógica do programa.
 */

#ifndef RASTROS_LOGICA_H
#define RASTROS_LOGICA_H
#include "../data.h"

/**
 * @brief Muda o caratér da jogada atual;
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada em que vai ser mudado o caratér (jogada atual);
 */
void changeCardinal (ESTADO *state, COORDENADA c);

/** @brief Verifica se é possível escolher a CASA pretendida.
 * A CASA escolhida pelo Jogador tem de estar na vizinhança da última jogada;
 * As coordenadas para a nova jogada tem de ter 1 de distância, como se verifica no gráfico que se segue:
 *   . . .
 *   . * .
 *   . . .
 *
 * Neste sentido, o Jogador (marcado com '*') pode mover-se para cada uma das casas marcadas com '.'.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada que o Jogador quer jogar;
 * @return 1 ou 0, caso se encontre ou não na sua vizinhança, respetivamente;
 */
int verificaVizinhanca (ESTADO *state, COORDENADA c);

/** @brief Verifica se a jogada é possível utilizando as funções obterEstadoCasa (definida no módulo data.c) e verificaVizinhança.
 * A jogada é possível se a CASA escolhida pelo Jogador estiver VAZIA ou for o JOGADOR1/JOGADOR2 (Verficado através da função -> obterEstadoCasa);
 * É necessário que a casa esteja na vizinhança (Verificado através da função -> verificaVizinhanca).
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada que o Jogador quer jogar;
 * @return 1 ou 0, caso a jogada seja possível ou não, respetivamente;
 */
int verificaCasa (ESTADO *state, COORDENADA c);

/** @brief Atualiza o histórico de jogadas no respetivo Jogador.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 */
void atualizaJogadas (ESTADO *state, COORDENADA c);

/** @brief Converte uma CASA para o tipo char correspondente.
 *  1. VAZIO: '.';
 *  2. BRANCA: '*';
 *  3. JOGADOR1: '1';
 *  4. JOGADOR2: '2';
 *
 * @param house Casa que pretendemos converter;
 * @return casa convertida mediante o char correspondente;
*/
char converteCasa (CASA house);

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

/** brief Verifica se o Jogador chegou ao fim.
 *
 * @param state Apontador para o estado do programa;
 * @return 1 ou 0, caso o Jogador tenha chegado ao fim ou não, respetivamente;
 */
int verificaFim(ESTADO *state);


/** Funções para o interpretador */

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


/** @brief Imprime uma mensagem.
 * Imprime uma mensagem para gravar ou ler o Jogo, caso o Jogador queira;
 *
 * @param state Apontador para o estado do programa;
 * @param nomeFicheiro Ficheiro onde se vai gravar o Jogo;
 * @return
 */
int gravarJogo (ESTADO *state, char *nomeFicheiro);

/** @brief Converte dois char's para um dígito.
 *
 * Usada na 'lerJogo';
 * @param jogada Jogada;
 * @return Retorna os respetivos char contidos na Jogada em decimal;
 */
int converteDecimal (char jogada[]);

/** @brief Remove caractéres extra.
 *
 * @param s String à qual vai ser removida os caractéres;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int removeCarateresExtra (char *s);

/** @brief Atualiza a coordenada após a jogada.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @param jogador Jogador que efetuou a jogada;
 * @return 0 ou !0, caso funcione ou não, respetivamente;
 */
int atualizaCoordenadaJogada (ESTADO *state, COORDENADA c, int jogador);

/** @brief: Lê o jogo.
 *
 * Acede ao ficheiro inserido pelo utilizador e atualiza o estado do jogo;
 * @param state Apontador para o estado do programa;
 * @param nome Ficheiro Ficheiro do qual se está a ler o programa;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int lerJogo (ESTADO *e, char *nomeFicheiro);

/** @brief Imprime um número de apenas 1 dígito em dois, acresentando um zero atrás.
 *
 * Números de dois dígitos permancem inalterados.
 * Neste caso, imprime no terminal e não num ficheiro.
 *
 * @param state Apontador para o estado do programa.
 */
void digitosTerminal (int i);

/** @brief Lê movimentos. Função aplicada no comando movs.
 *
 * @param state Apontador para o estado do programa.
 * @return 0 caso seja possível efetuar este comando.
 */
int lerMovimentos (ESTADO *e);

/**@brief Atualiza o estado de uma casa numa determinada coordenada, bem como a Jogada.
 * Modificada a última Jogada.
 * Muda o Estado de BRANCA para PRETA.
 *
 * @param novo Apontador para o estado do programa.
 * @param c Coordenada Atual.
 */
void posAux (ESTADO *novo, COORDENADA c);

/** @brief Função aplicada no comando pos.
 *
 *  @param state Apontador para o estado do programa.
 *  @param pos Array de Char que indica até que jogada é suposto mostrar o tabuleiro.
 */
int mostraPos(ESTADO *state, char *pos);

/**@brief Função para obter o número de Jogadas que o Jogador(Atual) pode efetuar.
 *
 * @param state Apontador para o estado do programa.
 * @return o número de Jogadas que o Jogador pode efetuar.
 */
int verificaPossibilidades (ESTADO *state);

#endif //RASTROS_LOGICA_H
