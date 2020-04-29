
/** @file
 * @brief Definição das funções da camada de dados do programa.
 */

#ifndef RASTROS_DATA_H
#define RASTROS_DATA_H

#include "../globals/globals.h"
#define CASA_VAZIO '.'
#define CASA_BRANCA '*'
#define CASA_PRETA '#'
#define CASA_JOGADOR1 '1'
#define CASA_JOGADOR2 '2'
typedef enum {VAZIO, BRANCA, PRETA,JOGADOR1,JOGADOR2} CASA;

typedef enum {NO,YES} BOT;

typedef struct coordenada {
    int linha, coluna;
} COORDENADA;

typedef struct jogada {
    COORDENADA jogador1, jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct estado {
    CASA tab[MAX_HOUSES][MAX_HOUSES];
    COORDENADA ultimaJogada;
    JOGADAS jogadas;
    BOT bot;
    int numJogadas, maxJogadas;
    int numComandos, maxComandos;
    int jogadorAtual;
    int nivel;
} ESTADO;

typedef struct in {
    char *comando,*argumento;
} INPUT;

typedef struct listas *LISTA;

typedef struct listas {
    void *valor;
    LISTA proxima;
} Nodo;


/**
 * \brief Inicializa o tabuleiro.
 *
 * @param state Apontador para o estado do programa;
 */
void initBoard (ESTADO *state);

/**
 * \brief Inicializa o jogo na posição e5.
 *
 * @param state Apontador para o estado do programa;
 */
void initPlay (ESTADO *state);

/**
 * \brief Inicializa o programa com o Jogador 1 e 0 jogadas;
 *
 * @param state Apontador para o estado do programa;
 */
void initPlayer (ESTADO *state);

/**
 * \brief Cria o Estado.
 *
 * @return Apontador do estado criado;
 */
ESTADO *initState ();

/**
 * @brief Lê a última coordenada jogada
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return Apontador para uma coordenada que contém os valores da última jogada
 */
COORDENADA *obterUltimaJogada (ESTADO *state);

/**
 * \brief Busca o jogador que está a jogar.
 *
 * @param state Apontador para o estado do programa;
 * @return Retorna o Jogador atual;
 */
int obterJogador (ESTADO *state);

/**
 * \brief Encontra a CASA da coordenada dada.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @return Retorna a CASA em questão;
 */
CASA obterEstadoCasa(ESTADO *state, COORDENADA c);

/**
 * \brief Obtém o número de jogadas;
 *
 * @param state Apontador para o estado do programa;
 * @return Número de jogadas;
 */
int obterNumeroJogadas (ESTADO *state);

/**
 * @brief Conta o número de comandos.
 *
 * @param state Apontador para o estado do programa;
 * @return Multiplica por 2 e soma 1 no caso do Jogador 1 ou multiplica por 2 e soma 2 no caso do Jogador 2, ambos os casos através do número de jogadas;
 */
int numeroComandos(ESTADO *state);

/**
 * @brief Vai ler o número máximo de comandos que foram jogados
 * 
 * Utilizado para lerJogada, mostraPos.
 * @param state Apontador para o estado do programa
 * 
 * @return máximo de comandos
 */
int obterMaxComandos (ESTADO *state);

/** @brief Converte um caractér para CASA.
 *
 * @param c Caractér associado à casa;
 * @return Retorna a CASA em questão;
 */
CASA converteChar (int c);

/** @brief Verifica sse pode jogar naquela CASA.
 *
 * @param casa Casa que pretendemos jogar;
 * @return 1 ou 0, caso seja possível jogar ou não, respetivamente;
 */
int podeJogar(CASA casa);

/**
 * @brief Vai buscar o número máximo de jogadas
 * 
 * Função utilizada na mostraPos para manter a possibilidade de fazer vários pos
 * sem perder a posição atual
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return número máximo de jogadas (posições)
 */
int obterMaxJogadas (ESTADO *state);

/**
 * @brief Inicializa o input
 * 
 * @return Apontador para o input inicializado
 */
INPUT *initInput();

/**
 * @brief Lê o nível atual do bot.
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return Nível do bot
 */
int obterNivelBot(ESTADO *state);

/**
 * @brief Altera o estado do bot.
 * 
 * @param state Apontador para o estado do jogo
 */
void alteraEstadoBot(ESTADO *state);

/**
 * @brief Altera o nível do bot.
 * 
 * @param state Apontador para o estado do jogo
 */
void alteraNivelBot(ESTADO *state, int nivel);

/**
 * @brief Retorna o estado do bot
 * 
 * @param state Apontador para o estado do programa
 * 
 * @return 0 se está desativado
 *         1 se está ativado
 */
int lerEstadoBot(ESTADO *state);

/**
 * @brief Lê qual o valor da linha ou da coluna numa determinada jogada
 *        e jogador.
 * 
 * @param state Apontador para o estado do programa
 * @param jogador Jogador 1 ou jogador 2
 * @param jogada Número da jogada a ser lida
 * @param tipo Se vai ler uma linha ou coluna:
 *        'c' para coluna
 *        'l' para linha
 * 
 * @return A coluna/linha que foi jogada numa jogada por um jogador.
 */
char obterLinhaColuna (ESTADO *state, int jogador, int jogada, char tipo);

/**
 * @brief  Lê o argumento ou o comando do input
 *
 * @param input apontador para o input
 * @param escolha Escolher entre ler o argumento ou o comando
 *       <0 para argumento
 *        0 para comando
 *
 * @return O argumento/comando desejado
 */
char *obterArgumentoComando (INPUT *input, int escolha );

#endif //RASTROS_DATA_H
