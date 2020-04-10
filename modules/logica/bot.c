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
    char *sourceF = argv[1], *destinF = argv[2];
    
    if(argc == 3) {
    
        if( (r = lerJogo(state,sourceF)) ==0 ) {
            if ((r = jogaBot(state)) == 0)
                r=gravarJogo(state,destinF);
        }
    } else {
        printf("Insira o comando corretamente:\n");
        printf("jog source destination\n");
        r=1;
    }
    if (r==1) {
        printf("Verifique se o nome do ficheiro está correto!");
    } else if (r==2) {
        printf("Não há jogadas possíveis. O jogador %d já ganhou!\n", verificaFim(state));
    }
    
    return r;
}