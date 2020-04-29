/** @file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ficheiros.h"
#include "../logica/logica.h"
#include "interface.h"
#include "../../globals/globals.h"


void removerLinha (char *string) {
    int i;
    for(i=0; string[i] && string[i] != '\n';i++);
    if(string[i] == '\n') string[i]='\0';
}

int gravarJogo (ESTADO *state, char *nomeFicheiro) {
    int m,n,i, nJog;
    FILE *save;
    int r=0;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    removerLinha(nomeFicheiro);
    strcat(dir,nomeFicheiro);
    save = fopen(dir,"w+"); /*! <Abre o ficheiro para gravar */
    if (save == NULL) r=1;
    else {
        for (m=MAX_HOUSES-1; m>=0;m--) {
            for(n=0;n<MAX_HOUSES;n++) {
                fprintf(save,"%c", converteCasa(state->tab[m][n])); /*!< Imprime a casa no ficheiro de texto temporário */
            }
            fprintf(save,"\n");
        }
        fprintf(save,"\n");
        for(i=0, nJog=obterNumeroJogadas (state); i <= nJog;i++) {
            imprimirJogadas(state,i, save);
        }
        fclose(save); /*! <Fecha o ficheiro temporário */
    }

    return r;

}

void numeros2Digitos (int i, FILE *save){
    if (i+1 < 10) fprintf (save,"0%d:", i+1);
    else fprintf(save, "%d:", i+1);
}



void imprimirJogadas (ESTADO *state, int i, FILE *save){
    if (i < obterNumeroJogadas(state)){
        numeros2Digitos(i, save);
        fprintf(save," %c%c",obterLinhaColuna(state, 1, i, 'c'),obterLinhaColuna(state, 1, i, 'l'));
        fprintf(save," %c%c\n", obterLinhaColuna(state, 2, i, 'c'),obterLinhaColuna(state, 2, i, 'l'));
    }
    else if (i == obterNumeroJogadas(state) && obterJogador(state) == 2){
        numeros2Digitos (i, save);
        fprintf(save," %c%c",obterLinhaColuna(state, 1, i, 'c'),obterLinhaColuna(state, 1, i, 'l'));
    }
}

int lerJogada (ESTADO *state, char *cadaToken) {
    int r=0;
    char numJogada[3],col1[2],col2[2],lin1[2],lin2[2];
    JOGADA jogad;
    if(sscanf(cadaToken,"%s %[a-h]%[1-8] %[a-h]%[1-8]",numJogada,col1,lin1,col2,lin2) == 5) {
        state->numJogadas=atoi(numJogada)-1;
        state->numComandos=numeroComandos(state) + 2;
        jogad.jogador1.coluna = *col1 - 'a'; jogad.jogador1.linha = *lin1 - '1';
        jogad.jogador2.coluna = *col2 - 'a'; jogad.jogador2.linha = *lin2 - '1';
        atualizaCoordenadaJogada(state,&jogad.jogador1,1);
        atualizaCoordenadaJogada(state,&jogad.jogador2,2);
        state->numJogadas++;
    } else if (sscanf(cadaToken,"%s %[a-h]%[1-8]", numJogada,col1,lin1) == 3) {
        state->numJogadas=converteDecimal(numJogada)-1;
        state->numComandos=numeroComandos(state)+1;
        jogad.jogador1.coluna = *col1 - 'a'; jogad.jogador1.linha = *lin1 - '1';
        atualizaCoordenadaJogada(state,&jogad.jogador1,1);
        state->jogadorAtual=1;
    } else r=2;

    return r;

}

int lerJogo (ESTADO *state, char *nomeFicheiro) {
    FILE *ficheiro;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    int m,n,i=0;
    char *restoFicheiro = calloc (BUF_SIZE, sizeof(char));
    char c,*token="\n", *cadaToken;
    int r=0;
    initBoard(state); /*!< Faz reset do estado atual */
    initPlay(state);
    initPlayer(state);

    removerLinha(nomeFicheiro); //!< Remove o caracter '\n'
    strcat(dir,nomeFicheiro);
    ficheiro=fopen(dir,"r+");

    if (ficheiro == NULL) r = 1; //!< Se não for possível abrir o ficheiro, dá erro.
    else {
        for(m=MAX_HOUSES-1;m>=0;m--){ /*!< Inicia a construção do tabuleiro a partir da leitura do ficheiro */
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

        for(i=0; (c=fgetc(ficheiro)) != EOF ; i++)
            restoFicheiro[i] = c;

        cadaToken = strtok(restoFicheiro,token); /*!< Começa a percorrer o resto do ficheiro (histórico de jogadas) */
        while (cadaToken != NULL && !r) {
            if(!removeCarateresExtra(cadaToken)) {
                r = lerJogada(state, cadaToken);
            }
            cadaToken = strtok(NULL,token);
        }

        state->maxJogadas=obterNumeroJogadas(state);
        state->maxComandos=numeroComandos(state);

        fclose(ficheiro);
        free(cadaToken);
    }
    free(restoFicheiro);
    return r;
}
