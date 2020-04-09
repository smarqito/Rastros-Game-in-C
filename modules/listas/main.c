#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"

int main() {
  LISTA L = criarLista();
  char linha[BUF_SIZE];
    
  printf("Insira várias linhas, acabando com CTRL-D:\n");

  // control-D é a tecla CTRL e a tecla D ao mesmo tempo
  // Em windows é capaz de ser CTRL-Z
    while(fgets(linha, BUF_SIZE, stdin) != 0) {
        // A função strdup cria uma cópia da string que foi lida
        L = insereCabeca(L, strdup(linha));
    }

  printf("\n==============================\n");
  printf(  "=          PERCURSO          =\n");
  printf(  "==============================\n\n");
    // percorre sem remover os elementos da lista
    for(LISTA T = L; !listaEstaVazia(T); T = proximo(T)) {
        char *str = (char *) devolveCabeca(T);
        printf("%s", str);
    }

  printf("\n==============================\n");
  printf(  "=           REMOCAO          =\n");
  printf(  "==============================\n\n");
    // percorre e vai removendo a cabeça
    while(!listaEstaVazia(L)) {
        char *str = (char *) devolveCabeca(L);
        L = removeCabeca(L);
        printf("%s", str);
        free(str);
    }
  return 0;
}