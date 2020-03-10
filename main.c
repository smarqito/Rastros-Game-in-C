#include "modules/data.h"
#include "modules/interpretador.h"

int main() {
    ESTADO *e = initState();
    interpretador(e);
    return 0;
}
/*
int main() {
    int i;
    char ip[MAXCHAR],c;
    printf("Bem vindo ao jogo Rastros\n");

    while (!sair(ip)){
        printf(("Diga-nos a sua instrução: "));
        for(i=0; (c=getchar()) != '\n' && i < MAXCHAR; i++)
            ip[i] = c;
        ip[i]='\0';
        executaInstr(ip);
    }

    return 0;
}*/