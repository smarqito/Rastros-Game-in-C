/**
 * @file
 * @brief Funções para listas ligadas
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

LISTA criarLista () {
    LISTA novaLista;
    // novaLista=NULL;
    novaLista = calloc(1,sizeof(Nodo));
    novaLista->proxima=NULL;
    return novaLista;
}

LISTA insereCabeca (LISTA l, void *valor) {
    LISTA novoNodo = criarLista();
    novoNodo->valor = valor;
    novoNodo->proxima=l;
    return novoNodo;
}

void *devolveCabeca (LISTA l) {
    void *cabeca;
    if (l==NULL) cabeca = NULL;
    else cabeca = l->valor;
    return cabeca;
}

LISTA proximo (LISTA l) {
    LISTA apontaProx;
    if (l==NULL) apontaProx=NULL;
    else apontaProx = l->proxima;
    return apontaProx;
}

LISTA removeCabeca (LISTA l) {
    LISTA clone;
    clone = l;
    l = proximo(l);
    free(clone);
    return l;   
}

int listaEstaVazia (LISTA l) {
    int r=0;
    if (l==NULL) r=1;
    return r;
}

int lengthLista (LISTA l) {
    int i;
    for (i=0; l!=NULL; l=l->proxima)
        i++;
    return i;
}