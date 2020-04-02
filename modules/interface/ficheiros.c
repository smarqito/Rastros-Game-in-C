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
    string[i]='\0';
}

void escreveHistorico (ESTADO *state) {
    FILE *temp;
    temp=fopen("temp","a");

    if(state->jogadorAtual) { //se o jogador atual é 1, a última jogada foi do 0!
        fprintf(temp,"%d: %c%c ",state->numJogadas+1,state->ultimaJogada.coluna + 'a',state->ultimaJogada.linha + '1');
    } else {
        fprintf(temp,"%c%c\n",state->ultimaJogada.coluna + 'a',state->ultimaJogada.linha + '1');
    }
    fclose(temp);
}

void verificaHistorico(ESTADO *state) {
    FILE *temp;
    if(!state->numJogadas && !state->jogadorAtual) {
        temp=fopen("temp","w+");
    }
}

int gravarJogo (ESTADO *state, char *nomeFicheiro) {
    int m,n,i;
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
        for(i=0;i<= state->numJogadas;i++) {
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
    if (i < state->numJogadas){
        numeros2Digitos(i, save);
        fprintf(save," %c%c",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
        fprintf(save," %c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
    }
    else if (i == state->numJogadas && obterJogador(state) == 2){
        numeros2Digitos (i, save);
        fprintf(save," %c%c",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
    }
}

int lerJogo (ESTADO *state, char *nomeFicheiro) {
    FILE *ficheiro;
    COORDENADA coordJog1, coordJog2;
    char dir[BUF_SIZE] = LOCAL_GRAVAR_FICHEIROS;
    int m,n,i=0;
    char numJogada[3], lin1, col1, lin2, col2,*restoFicheiro = malloc (BUF_SIZE * sizeof(char));
    char c,*token={"\n"}, *cadaToken;
    int r=0;
    initBoard(state);
    initPlay(state);
    initPlayer(state);
    removerLinha(nomeFicheiro);
    strcat(dir,nomeFicheiro);
    ficheiro=fopen(dir,"r+");
    if (ficheiro == NULL) r = 1;
    else {
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

                        printf("cada token: %s\n", cadaToken);
                    }
                    state->numJogadas++;
                } else if(strlen(cadaToken) == 5) {
                    if (sscanf(cadaToken,"%s %c%c", numJogada,&col1,&lin1)) {
                        printf("IF 2: %d\n", state->numJogadas);
                        state->numJogadas=converteDecimal(numJogada)-1;
                        coordJog1.coluna = col1-'a'; coordJog1.linha=lin1-'1';
                        atualizaCoordenadaJogada(state,coordJog1,1);
                    }
                    state->jogadorAtual=1;
                }
                printf("%d\n", numeroComandos(state));
            }
            cadaToken = strtok(NULL,token);
        }
        fclose(ficheiro);
    }
    return r;
}
