//
// Created by marco on 3/3/20.
//

#include "coordenada.h"
#include "../ficheiros.h"

void adicionaCoordenada (char *fileName, char *coord, int player)
{
    atualizarTab("temp.txt", 3,4);
}

int validaCoord (char s[3]){
    int resp;
    resp = 0;
    if ( s[0] >= 'a' && s[0] <= 'h' && s[1] > '0' && s[1] <= '8') resp = 1;
    return resp; //Caso a resp (Resposta) for 1 - Coordenada Válida/ Caso contrário - 0
}

