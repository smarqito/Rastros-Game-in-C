//
// Created by marco on 3/9/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"

int interpretador (ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2];

    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 0;

    if(strlen(linha) == 3 && sscanf(linha, "%[a-h]%[1-8]", &col, &lin) == 2) {
        COORDENADA coord = {*col - 'a', *lin - '1'};
        //jogar(e,coord);
        //mostrarTabuleiro(e);
    }
    return 1;
}