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

/** 
 * @brief Verifica se é possível escolher a CASA pretendida.
 *
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

/**
 * @brief Verifica se a jogada é possível utilizando as funções obterEstadoCasa (definida no módulo data.c) e verificaVizinhança.
 *
 * A jogada é possível se a CASA escolhida pelo Jogador estiver VAZIA ou for o JOGADOR1/JOGADOR2 (Verficado através da função -> obterEstadoCasa);
 * É necessário que a casa esteja na vizinhança (Verificado através da função -> verificaVizinhanca).
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada que o Jogador quer jogar;
 * @return 1 ou 0, caso a jogada seja possível ou não, respetivamente;
 */
int verificaCasa (ESTADO *state, COORDENADA c);

/**
 * @brief Atualiza o número máximo de jogadas
 * 
 * Utiliza a jogadaAtual para atualizar o máximo de jogadas disponíveis.
 * 
 * @param state Apontador para o estado do programa
 */
void atualizaMaxJogadas (ESTADO *state);

/** @brief Atualiza o histórico de jogadas no respetivo Jogador.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 */
void atualizaJogadas (ESTADO *state, COORDENADA c);

/**
 * @brief Divide um determinado input em comando e argumento.
 *
 * @param resposta Apontador para o struct INPUT que vai receber a divisão
 * @param input Linha de texto inserida pelo utilizador.
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int divideInput (INPUT *resposta, char *input);

/** 
 * @brief Converte uma CASA para o tipo char correspondente.
 *
 *  1. VAZIO: '.';
 *  2. BRANCA: '*';
 *  3. JOGADOR1: '1';
 *  4. JOGADOR2: '2';
 *0
 * @param house Casa que pretendemos converter;
 * @return casa convertida mediante o char correspondente;
*/

char converteCasa (CASA house);


/** 
 * @brief Verifica se o Jogador chegou ao fim.
 *
 * @param state Apontador para o estado do programa;
 * @return 0 se o jogo não acabou
 *         ~0 número do jogador que venceu
 */
int verificaFim(ESTADO *state);


/** Funções para o interpretador */


/** 
 * @brief Converte dois char's para um dígito.
 *
 * @param jogada Jogada;
 * 
 * @return Retorna os respetivos char contidos na Jogada em decimal;
 */
int converteDecimal (const char *jogada);

/** 
 * @brief Remove caractéres extra.
 *
 * @param s String à qual vai ser removida os caractéres;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int removeCarateresExtra (char *s);

/** 
 * @brief Atualiza a coordenada após a jogada.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @param jogador Jogador que efetuou a jogada;
 * 
 * @return 0 ou ~0, caso funcione ou não, respetivamente;
 */
int atualizaCoordenadaJogada (ESTADO *state, COORDENADA *c, int jogador);

/**
 * @brief Atualiza o estado de uma casa numa determinada coordenada, bem como a Jogada.
 *
 * Modificada a última Jogada.
 * Muda o Estado de BRANCA para PRETA.
 *
 * @param novo Apontador para o estado do programa.
 * @param c Coordenada Atual.
 */
void posAux (ESTADO *novo, COORDENADA c);

/** 
 *  @brief Função aplicada no comando pos.
 *
 *  @param state Apontador para o estado do programa.
 *  @param pos Array de Char que indica até que jogada é suposto mostrar o tabuleiro.
 */
void mostraPos(ESTADO *state, char *pos);

/**
 * @brief Calcula o número de jogadas possíveis e quais as respetivas coordenadas
 * a partir coordenada da última jogada.
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return Número de jogadas possíveis
 * 
 */
LISTA coordenadasPossiveis (ESTADO *state);

/**
 * @brief Cria um apontador do tipo void para uma coordenada
 */
COORDENADA *criaCoordenada (COORDENADA c);

/**
 * @brief Função para obter o número de Jogadas que o Jogador(Atual) pode efetuar.
 *
 * @param state Apontador para o estado do programa.
 * 
 * @return o número de Jogadas que o Jogador pode efetuar.
 */
int verificaPossibilidades (ESTADO *state);

/**
 * @brief Atualiza o número de jogadas com um inteiro recebido como argumento
 * 
 * @param state Apontador para o estado do jogo
 * @param numJog Novo número de jogadas
 */
void atualizaJogadasEstatico (ESTADO *state, int numJog);

/**
 * @brief Atualiza o número de jogadas com argumento
 * 
 * @param state Apontador para o estado do programa
 * @param numComandos Novo número de comandos
 */
void atualNumComandosEstatico (ESTADO *state, int numComandos);

/**
 * @brief Atualiza o jogador atual
 * 
 * @param state Apontador para o estado do programa
 * @param jogador Próximo jogador
 *        0 -> Jogador 1
 *        1 -> Jogador 2
 */
void atualizaJogAtual (ESTADO *state, int jogador);

#endif //RASTROS_LOGICA_H
