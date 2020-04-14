/**
 * @file
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../data.h"
#include "../interface/ficheiros.h"
#include "auxiliaresBot.h"
#include "../../globals/globals.h"
#include "logica.h"

int main (int argc, char *argv[]) {
    int r=0;
    ESTADO *state = initState();
    COORDENADA *ultJogada;
    char *sourceF = argv[1], *destinF = argv[2];
    
    if(argc == 3) {
    
        if( (r = lerJogo(state,sourceF)) ==0 ) {
            if ((r = jogaBot(state)) == 0) {
                r=gravarJogo(state,destinF);
                ultJogada = obterUltimaJogada(state);
                printf(COR_VERDE "Efetuado a jogada %c%c.\n", ultJogada->coluna+'a', ultJogada->linha+'1');
                printf("Nível da jogada: %d\n\n", obterNivelBot(state));
            }
        }
    } else {
        printf(COR_CIANO"Insira o comando corretamente:\n");
        printf(NEGRITO_ON "jog " COR_VERDE_NEGRITO "fichOrigem" COR_VERMELHO_NEGRITO " destination" RESET "\n");
        r=1;
    }
    if (r==1) {
        printf(COR_VERMELHO "\nVerifique se o nome do ficheiro de origem está correto!\n");
    } else if (r==2) {
        printf(COR_VERMELHO "Não há jogadas possíveis. O jogador %d já ganhou!\n", verificaFim(state));
    }
    
    return r;
}