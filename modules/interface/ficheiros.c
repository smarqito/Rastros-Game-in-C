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

int lerJogada (ESTADO *state, char *cadaToken) {
    int r=0;
    char numJogada[3],col1[2],col2[2],lin1[2],lin2[2];
    COORDENADA coordJog1, coordJog2;
    if(strlen(cadaToken) == 8){
        if(sscanf(cadaToken,"%s %[a-h]%[1-8] %[a-h]%[1-8]",numJogada,col1,lin1,col2,lin2) == 5) {
            state->numJogadas=atoi(numJogada)-1;
            state->numComandos=numeroComandos(state) + 2;
            coordJog1.coluna = *col1 - 'a'; coordJog1.linha = *lin1 - '1';
            coordJog2.coluna = *col2 - 'a'; coordJog2.linha = *lin2 - '1';
            atualizaCoordenadaJogada(state,&coordJog1,1);
            atualizaCoordenadaJogada(state,&coordJog2,2);
            state->numJogadas++;
        } else r=2;
    } else if(strlen(cadaToken) >= 5) {
        if (sscanf(cadaToken,"%s %[a-h]%[1-8]", numJogada,col1,lin1) == 3) {
            state->numJogadas=converteDecimal(numJogada)-1;
            state->numComandos=numeroComandos(state)+1;
            coordJog1.coluna = *col1 - 'a'; coordJog1.linha = *lin1 - '1';
            atualizaCoordenadaJogada(state,&coordJog1,1);
            state->jogadorAtual=1;
        } else r=2;
    } else {
        r = 2;
    }

    return r;

}

int lerJogo (ESTADO *state, char *nomeFicheiro) {
    FILE *ficheiro;
    COORDENADA coordJog1, coordJog2;
    char dir[] = LOCAL_GRAVAR_FICHEIROS;
    int m,n,i=0;
    char *restoFicheiro = malloc (BUF_SIZE * sizeof(char));
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

        // do {
        //     c=fgetc(ficheiro);
        //     if(feof(ficheiro))
        //         break;
        //     restoFicheiro = (char *) c;
        // } while (1);
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
