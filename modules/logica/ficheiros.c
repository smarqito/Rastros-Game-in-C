/** @file */

#include "ficheiros.h"
#include "logica.h"
#include <stdio.h>
#include <string.h>


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
    for(i=0;i<= state->numJogadas;i++) {
        imprimirJogadas(state,i, save);
    }
    fclose(save); /*! <Fecha o ficheiro temporário */

    return 0;

}

void numeros2Digitos (int i, FILE *save){
    if (i+1 < 10) fprintf (save,"0%d: ", i+1);
    else fprintf(save, "%d: ", i+1);
}



void imprimirJogadas (ESTADO *state, int i, FILE *save){
    if (i < state->numJogadas){
        numeros2Digitos(i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
        fprintf(save,"%c%c\n", state->jogadas[i].jogador2.coluna+'a',state->jogadas[i].jogador2.linha+'1');
    }
    else if (i == state->numJogadas && obterJogador(state) == 2){
        numeros2Digitos (i, save);
        fprintf(save,"%c%c ",state->jogadas[i].jogador1.coluna+'a',state->jogadas[i].jogador1.linha+'1');
    }
}
