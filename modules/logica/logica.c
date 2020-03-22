/** @file
 * @brief Definição das função da camada de lógica do programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logica.h"
#include "../interface/interface.h"

/**
 * @brief Muda o caratér da jogada atual;
 *
 * @param state Estado do jogo;
 * @param c Coordenada em que vai ser mudado o caratér (jogada atual);
 */
void changeCardinal (ESTADO *state, COORDENADA c) {
    int m,n;
    m=state->ultimaJogada.linha; /*! <Linha da jogada */
    n=state->ultimaJogada.coluna; /*! <Coluna da jogada */
    state->tab[m][n] = PRETA; /*! <Jogada anterior -> '#' */
    state-> tab[c.linha][c.coluna] = BRANCA; /*! <Jogada atual -> '*' */
}

/** @brief Verifica se é possível escolher a CASA pretendida.
 * A CASA escolhida pelo Jogador tem de estar na vizinhança da última jogada;
 * As coordenadas para a nova jogada tem de ter 1 de distância, como se verifica no gráfico que se segue:
 *   . . .
 *   . * .
 *   . . .
 *
 * Neste sentido, o Jogador (marcado com '*') pode mover-se para cada uma das casas marcadas com '.'.
 *
 * @param state Estado do jogo;
 * @param c Coordenada que o Jogador quer jogar;
 * @return 1 ou 0, caso se encontre ou não na sua vizinhança, respetivamente;
 */
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




/** @brief Verifica se a jogada é possível utilizando as funções getHouseState (definida no módulo data.c) e verificaVizinhança.
 * A jogada é possível se a CASA escolhida pelo Jogador estiver VAZIA ou for o JOGADOR1/JOGADOR2 (Verficado através da função -> getHouseState);
 * É necessário que a casa esteja na vizinhança (Verificado através da função -> verificaVizinhanca).
 *
 * @param state Estado do jogo;
 * @param c Coordenada que o Jogador quer jogar;
 * @return 1 ou 0, caso a jogada seja possível ou não, respetivamente;
 */
int verificaCasa (ESTADO *state, COORDENADA c){
    int resposta = 0;
    if ((   getHouseState(state,c) == VAZIO
         || getHouseState(state,c) == JOGADOR1
         || getHouseState(state,c) == JOGADOR2)
        && verificaVizinhanca(state, c))
            resposta = 1;
    return resposta;
}

/** @brief Atualiza o histórico de jogadas no respetivo Jogador.
 *
 * @param state Estado do jogo;
 * @param c Coordenada Atual;
 */
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


/** @brief Converte uma CASA para o tipo char correspondente.
 * 1. VAZIO: '.';
 *  2. BRANCA: '*';
 *  3. JOGADOR1: '1';
 *  4. JOGADOR2: '2';
 *
 * @param house Casa que pretendemos converter;
 * @return casa convertida mediante o char correspondente;
*/
char converteCasa (CASA house) {
    char casa;
    switch (house) {
        case VAZIO:
            casa = '.';
            break;
        case BRANCA:
            promptFormata(COR_VERMELHO_NEGRITO);
            casa = '#';
            break;
        case PRETA:
            promptFormata(COR_ROXO);
            casa = 'X';
            break;
        case JOGADOR1:
            promptFormata(COR_AMARELO_NEGRITO);
            casa = '1';
            break;
        case JOGADOR2:
            promptFormata(COR_AMARELO_NEGRITO);
            casa ='2';
            break;
    }
    return casa;
}


/** @brief Efetua (se possível) uma jogada.
 * Após verificar a condição (Função -> verificaCasa) modifica o ESTADO CASA (Para BRANCA);
 * Substitui no Tabuleiro o '*' por um '#' (Função -> changeCardinal);
 * Atualiza a última jogada;
 *
 * @param state Estado do jogo;
 * @param c Coordenada Atual;
 * @return 1 ou 0, caso a jogada seja possível ou não, respetivamente;
 */
int jogar (ESTADO *state, COORDENADA c){
    if (verificaCasa(state, c)){
        changeCardinal(state,c); /*! <Muda '*' e '#' */
        atualizaJogadas(state,c);
        mostrarTabuleiro(state);
        //printf("%c", converteCasa(state->tab[0][0]));
        return 1;
    }
    else {
        printf("Não é possível efetuar essa jogada! Tente Novamente.\n");
        return 0;
    }
}


/** brief Verifica se o Jogador chegou ao fim.
 *
 * @param state Estado do jogo;
 * @return 1 ou 0, caso o Jogador tenha chegado ao fim ou não, respetivamente;
 */
int verificaFim (ESTADO *state) {
    if(state->tab[MAX_HOUSES-1][MAX_HOUSES-1] == BRANCA)
        return 2;
    else if (state->tab[0][0]==BRANCA)
        return 1;
    else
        return 0;;
}


/** @brief  Imprime números com dois dígitos.
 * Exemplo.: 1 = 01 ou 2 = 02 (Números com dois digitos ficam inalterados);
 * Usada na função 'imprimirJogadas' e 'gravarJogo';
 *
 * @param i Número da Jogada;
 * @param save Ficheiro;
 */
void numeros2Digitos (int i, FILE *save){
    if (i+1 < 10) fprintf (save,"0%d: ", i+1);
    else fprintf(save, "%d: ", i+1);
}



/** @brief Imprime as Jogadas efetuadas (abaixo do tabuleiro).
 * Usada na função 'gravarJogo';
 *
 * @param state Estado do jogo;
 * @param i Número da Jogada;
 * @param save Ficheiro;
 */
void imprimirJogadas (ESTADO *state, int i, FILE *save){
    if (i < state->numJogadas){
        numeros2Digitos(i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
        fprintf(save,"%c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
    }
    else if (i == state->numJogadas && getPlayer(state) == 2){
        numeros2Digitos (i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
    }
}


/** @brief Imprime uma mensagem.
 * Imprime uma mensagem para gravar ou ler o Jogo, caso o Jogador queira;
 *
 * @param state Estado do Jogo;
 * @param nomeFicheiro Ficheiro onde se vai gravar o Jogo;
 * @return
 */
int gravarJogo (ESTADO *state, char *nomeFicheiro) {
    int m,n,i;
    FILE *save;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    i=0;
    while(nomeFicheiro[i]) {
        if (nomeFicheiro[i] == '\n') nomeFicheiro[i] = '\0';
        i++;
    }
    strcat(dir,nomeFicheiro);
    save = fopen(dir,"w+"); /*! <Abre o ficheiro temporário */
    for (m=MAX_HOUSES-1; m>=0;m--) {
        for(n=0;n<MAX_HOUSES;n++) {
            fprintf(save,"%c", converteCasa(state->tab[m][n])); /*! <Imprime a casa no ficheiro de texto temporário */
        }
        fprintf(save,"\n");
    }
    fprintf(save,"\n");
    for(i=0;i<= state->numJogadas;i++) {
        imprimirJogadas(state,i, save);
    }
    fclose(save); /*! <Fecha o ficheiro temporário */

    return 0;
}


/** @brief Converte dois char's para um dígito.
 *
 * Usada na 'lerJogo';
 * @param jogada Jogada;
 * @return Retorna os respetivos char contidos na Jogada em decimal;
 */
int converteDecimal (char jogada[]) {
    int x=0;
    x += (jogada[0]-'0') * 10;
    x += (jogada[1]-'0');
    return x;
}

/** @brief Remove caractéres extra.
 *
 * @param s String à qual vai ser removida os caractéres;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
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

/** @brief Atualiza a coordenada após a jogada.
 *
 * @param state Apontador para o estado do programa;
 * @param c Coordenada Atual;
 * @param jogador Jogador que efetuou a jogada;
 * @return 0 ou !0, caso funcione ou não, respetivamente;
 */
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

/** @brief: Lê o jogo.
 * Acede ao ficheiro inserido pelo utilizador e atualiza o estado do jogo;
 *
 * @param state Apontador para o estado do programa;
 * @param nomeFicheiro Ficheiro do qual se está a ler o programa;
 * @return 0 ou !0 caso funcione ou não, respetivamente;
 */
int lerJogo (ESTADO *state, char *nomeFicheiro) {
    FILE *ficheiro;
    COORDENADA coordJog1, coordJog2;
    int m,n,i=0;
    char numJogada[3], lin1, col1, lin2, col2,*restoFicheiro = malloc (BUF_SIZE * sizeof(char));
    char c,*token={"\n"}, *cadaToken;
    m=n=0;
    while(nomeFicheiro[n] && nomeFicheiro[n] != '\n') n++;
    nomeFicheiro[n]='\0';
    ficheiro=fopen(nomeFicheiro,"r+");
    for(m=MAX_HOUSES-1;m>=0;m--){
        for(n=0;n<MAX_HOUSES;n++){
            c=converteChar(fgetc(ficheiro));
            state->tab[m][n] = c;
            if(casaJogar(c)) {
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
                if(sscanf(cadaToken,"%s %c%c",numJogada,&col1,&lin1,&col2,&lin2)) {
                    state->numJogadas=converteDecimal(numJogada)-1;
                    coordJog1.coluna = col1-'a'; coordJog1.linha=lin1-'1';
                    coordJog2.coluna = col2-'a'; coordJog2.linha=lin2-'1';
                    atualizaCoordenadaJogada(state,coordJog1,1);
                    atualizaCoordenadaJogada(state,coordJog2,2);
                }
                state->numJogadas++;
            }
        }
        cadaToken = strtok(NULL,token);

    }
    fclose(ficheiro);
    mostrarTabuleiro(state);
    return 0;
}

/** @brief Lê movimentos. Função aplicada no comando movs;
 */
int lerMovimentos (ESTADO *e) {
    printf("apresentar movimentos do jogo");
    return 0;
}

/** @brief Função aplicada no comando pos;
 */
void mostraPos(ESTADO *state, char *pos) {
    printf("mostra um tabuleiro antigo na pos \"%s\".", pos);
}