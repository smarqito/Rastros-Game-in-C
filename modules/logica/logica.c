//
// Created by marco on 3/9/20.
//

#include <stdio.h>
#include "logica.h"

void changeCardinal (ESTADO *state) {
    int m,n;
    m=state->ultimaJogada.linha;
    n=state->ultimaJogada.coluna;
    state->tab[m][n] = PRETA;
}

// Verfica-se a CASA escolhida pelo Jogador (Tem de estar na proximidade)

int isPossiblePlay (ESTADO *state, COORDENADA c){
    COORDENADA ultima = state->ultimaJogada;
    int linhaU = ultima.linha, colunaU = ultima.coluna;
    int linhaA = c.linha, colunaA = c.coluna;
    int resposta = 0;
    if( linhaA == linhaU + 1 || linhaA == linhaU - 1 || linhaA == linhaU){
        if (colunaA == colunaU + 1 || colunaA == colunaU - 1 || colunaA == colunaU){
            resposta = 1;
        }
    }
    if (linhaA == linhaU && colunaA == colunaU) resposta = 0;
    return resposta;
}

// Verifica as condições necessárias para poder efetuar uma jogada -> Utilizada na função 'jogar'
//A jogada é possível se a CASA escolhida pelo Jogador estiver VAZIA ou for o JOGADOR1/JOGADOR2 (Verficado através da função -> getHouseState)
//É necessario que a casa esteja na proximidade do Jogador -> isPossiblePlay

int verificaCasa (ESTADO *state, COORDENADA c){
    int resposta = 0;
    if ((getHouseState(state,c) == VAZIO || getHouseState(state,c) == JOGADOR1 || getHouseState(state,c) == JOGADOR2) && isPossiblePlay(state, c)) resposta = 1;
    return resposta;
}

//Efetua a jogada (Caso seja possível)
//Após verificar a condição (Função -> verificaCasa) modifica o ESTADO CASA (Para BRANCA)
//Substitui no Tabuleiro o 'asterisco' por um cardinal (Função -> changeCardinal)
//Atualiza a última jogada
//Por fim retorna 1, caso a jogada seja possível, ou 0, caso contrário

int jogar (ESTADO *state, COORDENADA c){
    if (verificaCasa(state, c)){
        state-> tab[c.linha][c.coluna] = BRANCA;
        changeCardinal(state);
        state->ultimaJogada = c;
        return 1;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 0;
    }
}

int verificaFim (ESTADO *state) {
    if(state->tab[0][MAX_HOUSES-1] == BRANCA)
        return 2;
    else if (state->tab[MAX_HOUSES-1][0]==BRANCA)
        return 1;
    else
        return 0;;
}

int gravarJogo (ESTADO *state, char *nomeFicheiro) {
    printf("gravar %s", nomeFicheiro);
    return 0;
}

int lerJogo (ESTADO *e, char *nomeFicheiro) {
    printf("ler %s", nomeFicheiro);
    return 0;
}

int lerMovimentos (ESTADO *e) {
    printf("apresentar movimentos do jogo");
    return 0;
}

void mostraPos(ESTADO *state, char *pos) {
    printf("mostra um tabuleiro antigo na pos \"%s\".", pos);
}