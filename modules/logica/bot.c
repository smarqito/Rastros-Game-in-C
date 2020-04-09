//
// Created by marco on 3/10/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../listas/listas.h"
#include "logica.h"
#include "bot.h"
#include "../interface/interface.h"

int jogaBot (ESTADO *state) {
    int r,i;
    srand(time(0));

    LISTA l = coordenadasPossiveis(state);
    COORDENADA *jogadaBot;
    r = lengthLista(l);
    
    for(i = rand() % r; i>0; i--){
        proximo(l);

    }
    
    jogadaBot=devolveCabeca(l);

    jogar(state,*jogadaBot);

    return 0;
}

// int main (int argc, char *argv) {

// }