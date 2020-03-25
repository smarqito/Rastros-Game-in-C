/** @file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logica.h"
#include "../interface/interface.h"
#include "ficheiros.h"


void changeCardinal (ESTADO *state, COORDENADA c) {
    int m,n;
    m=state->ultimaJogada.linha; /*! <Linha da jogada */
    n=state->ultimaJogada.coluna; /*! <Coluna da jogada */
    state->tab[m][n] = PRETA; /*! <Jogada anterior -> '#' */
    state-> tab[c.linha][c.coluna] = BRANCA; /*! <Jogada atual -> '*' */
}


int verificaVizinhanca (ESTADO *state, COORDENADA c){
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



int verificaCasa (ESTADO *state, COORDENADA c){
    int resposta = 0;
    if ((obterEstadoCasa(state, c) == VAZIO
         || obterEstadoCasa(state, c) == JOGADOR1
         || obterEstadoCasa(state, c) == JOGADOR2)
        && verificaVizinhanca(state, c))
            resposta = 1;
    return resposta;
}


void atualizaJogadas (ESTADO *state, COORDENADA c) {
    if (!state->jogadorAtual) {
        state->jogadorAtual=1;
        state->jogadas[state->numJogadas].jogador1=c;
    } else {
        state->jogadorAtual=0;
        state->jogadas[state->numJogadas++].jogador2=c;
        // state->numJogadas++;
    }
    state->ultimaJogada=c;
}


char converteCasa (CASA house) {
    char casa;
    switch (house) {
        case VAZIO:
            casa = CASA_VAZIO;
            break;
        case BRANCA:
            promptFormata(COR_VERMELHO_NEGRITO);
            casa = CASA_BRANCA;
            break;
        case PRETA:
            promptFormata(COR_ROXO);
            casa = CASA_PRETA;
            break;
        case JOGADOR1:
            promptFormata(COR_AMARELO_NEGRITO);
            casa = CASA_JOGADOR1;
            break;
        case JOGADOR2:
            promptFormata(COR_AMARELO_NEGRITO);
            casa = CASA_JOGADOR2;
            break;
    }
    return casa;
}



int jogar (ESTADO *state, COORDENADA c){
    if (verificaCasa(state, c)){
        changeCardinal(state,c); /*! <Muda '*' e '#' */
        atualizaJogadas(state,c);
        mostrarTabuleiro(state);
        return 1;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 0;
    }
}


int verificaFim (ESTADO *state) {
    if(state->tab[MAX_HOUSES-1][MAX_HOUSES-1] == BRANCA)
        return 2;
    else if (state->tab[0][0]==BRANCA)
        return 1;
    else if (verificaPossibilidades(state))
        return (obterJogador(state) == 1) ? 2 : 1 ;
    else
        return 0;;
}


void numeros2Digitos (int i, FILE *save){
    if (i+1 < 10) fprintf (save,"0%d: ", i+1);
    else fprintf(save, "%d: ", i+1);
}



void imprimirJogadas (ESTADO *state, int i, FILE *save){
    if (i < obterJogadas(state)){
        numeros2Digitos(i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
        fprintf(save,"%c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
    }
    else if (i == obterJogadas(state) && obterJogador(state) == 2){
        numeros2Digitos (i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
    }
}


int gravarJogo (ESTADO *state, char *nomeFicheiro) {
    int m,n,i;
    FILE *save;

    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    removerLinha(nomeFicheiro);
    strcat(dir,nomeFicheiro);
    save = fopen(dir,"w+"); /*! <Abre o ficheiro para gravar */
    for (m=MAX_HOUSES-1; m>=0;m--) {
        for(n=0;n<MAX_HOUSES;n++) {
            fprintf(save,"%c", converteCasa(state->tab[m][n])); /*! <Imprime a casa no ficheiro de texto temporário */
        }
        fprintf(save,"\n");
    }
    fprintf(save,"\n");
    for(i=0;i<= obterJogadas(state) ;i++) {
        imprimirJogadas(state,i, save);
    }
    fclose(save); /*! <Fecha o ficheiro temporário */

    return 0;
}

int converteDecimal (char jogada[]) {
    int x=0;
    x += (jogada[0]-'0') * 10;
    x += (jogada[1]-'0');
    return x;
}

int removeCarateresExtra (char *s) {
    int i=0,n;
    while(s[i]) {
        if(s[i] == ':') {
            n=i;
            while(s[n]) {
                s[n] = s[n+1];
                n++;
            }
        }
        i++;
    }
    return 0;
}


int atualizaCoordenadaJogada (ESTADO *state, COORDENADA c, int jogador) {
    int numJogada = state->numJogadas;
    if(jogador == 1) {
        state->jogadas[numJogada].jogador1.coluna=c.coluna;
        state->jogadas[numJogada].jogador1.linha=c.linha;
    } else {
        state->jogadas[numJogada].jogador2.coluna=c.coluna;
        state->jogadas[numJogada].jogador2.linha=c.linha;
    }
    return 0;
}


int lerJogo (ESTADO *state, char *nomeFicheiro) {
    FILE *ficheiro;
    COORDENADA coordJog1, coordJog2;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    int m,n,i=0;
    char numJogada[3], lin1, col1, lin2, col2,*restoFicheiro = malloc (BUF_SIZE * sizeof(char));
    char c,*token={"\n"}, *cadaToken;
    removerLinha(nomeFicheiro);
    strcat(dir,nomeFicheiro);
    ficheiro=fopen(dir,"r+");
    for(m=MAX_HOUSES-1;m>=0;m--){
        for(n=0;n<MAX_HOUSES;n++){
            c=converteChar(fgetc(ficheiro));
            state->tab[m][n] = c;
            if(podeJogar(c)) {
                state->ultimaJogada.linha = m;
                state->ultimaJogada.coluna = n;
            }
        }
        fgetc(ficheiro);
    }
    i=0;
    while((c=fgetc(ficheiro)) != EOF)
        restoFicheiro[i++] = c;
    cadaToken = strtok(restoFicheiro,token); /*!< Começa a percorrer o resto do ficheiro */
    while (cadaToken != NULL) {
        if(!removeCarateresExtra(cadaToken)) {
            if(strlen(cadaToken) == 8){
                if(sscanf(cadaToken,"%s %c%c %c%c",numJogada,&col1,&lin1,&col2,&lin2)) {
                    state->numJogadas=converteDecimal(numJogada)-1;
                    coordJog1.coluna = col1-'a'; coordJog1.linha=lin1-'1';
                    coordJog2.coluna = col2-'a'; coordJog2.linha=lin2-'1';
                    atualizaCoordenadaJogada(state,coordJog1,1);
                    atualizaCoordenadaJogada(state,coordJog2,2);
                }
                state->numJogadas++;
            } else if(strlen(cadaToken) == 6) {
                if (sscanf(cadaToken,"%s %c%c", numJogada,&col1,&lin1)) {
                    state->numJogadas=converteDecimal(numJogada)-1;
                    coordJog1.coluna = col1-'a'; coordJog1.linha=lin1-'1';
                    atualizaCoordenadaJogada(state,coordJog1,1);
                }
                state->jogadorAtual=1;
            }
        }
        cadaToken = strtok(NULL,token);

    }
    fclose(ficheiro);
    mostrarTabuleiro(state);
    return 0;
}


void digitosTerminal (int i){
    if (i < 10) printf("0%d: ",i+1);
    else printf ("%d", i+1);
}


int lerMovimentos (ESTADO *state) {
    int i;
    for(i=0;i<= obterNumeroJogadas(state);i++){
        if (i < obterNumeroJogadas(state)){
            digitosTerminal (i);
            printf("%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
            printf("%c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
        }
        else if (i == obterNumeroJogadas(state) && obterJogador(state) == 2){
            digitosTerminal (i);
            printf("%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
        }
    }

    return 0;
}


void posAux (ESTADO *novo, COORDENADA c){
     changeCardinal(novo, c);
     atualizaJogadas(novo, c);
}

int mostraPos( ESTADO *state, char *pos) {
    int i,r=0;
    int c = atoi(pos) ; //! Número de jogadas que se pretende imprimir;
    //ESTADO *novo = initState();
    initBoard(state);
    initPlay(state);
    if (c==0) {
        initPlayer(state);
        mostrarTabuleiro(state);
    } else if (c < obterNumeroJogadas(state)) {
        initPlayer(state);
        for(i = 0; i < c; i++ ){ 
            COORDENADA jog1 = state->jogadas[i].jogador1;
            COORDENADA jog2 = state->jogadas[i].jogador2;
                posAux(state, jog1);
                posAux(state, jog2);
            }
        mostrarTabuleiro(state);

    } else {
        printf ("Não é possível efetuar esse comando!Tente novamente\n");
        printf("O intervalo de posições é de %d até %d\n", 0, (obterNumeroJogadas(state) > 0) ? 0 : (obterNumeroJogadas(state) - 1));
        r=1;
    }
    return r;
}

int verificaPossibilidades (ESTADO *state) {
    int r=0;
    int jogadorA = state->jogadorAtual;
    


    return r;
}