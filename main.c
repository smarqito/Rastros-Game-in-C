#include <stdio.h>
#include "globals.h"
#include "mainLogica.h"
void readInstr (char ip[]);
int main() {
    int i;
    char ip[MAXCHAR],c;

    printf("Bem vindo ao jogo Rastros\n");
    while (!exit(ip)){
        printf(("Diga-nos a sua instrução: "));
        for(i=0; (c=getchar()) != '\n' && i < MAXCHAR; i++)
            ip[i] = c;
        ip[i]='\0';
        executaInstr(ip);
    }
    return 0;
}