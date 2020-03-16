//
// Created by marco on 3/9/20.
//

#ifndef RASTROS_LOGICA_H
#define RASTROS_LOGICA_H
#include "../data.h"
int isPossiblePlay (ESTADO *state, COORDENADA c);
int jogar (ESTADO *state, COORDENADA c);
int verificaFim(ESTADO *state);
// funções para o interpretador
int gravarJogo (ESTADO *state, char *nomeFicheiro);
int lerJogo (ESTADO *e, char *nomeFicheiro);
int lerMovimentos (ESTADO *e);
void mostraPos(ESTADO *state, char *pos);
char converteCasa (CASA house);
#endif //RASTROS_LOGICA_H
