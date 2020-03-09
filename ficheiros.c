//
// Created by marco on 3/3/20.
//
#include "ficheiros.h"
#include <stdio.h>


void atualizarTab (char *fileName, int m, int n)
{
        // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
        FILE *pf;
        char conteudo[100],var2[100];

        //Abre o arquivo novamente para leitura
        pf = fopen("temp.txt", "r");

        // Le em conteudo o valor da variável armazenada anteriormente pf
        fread(&conteudo, 2, 4,pf);
        fread(&var2, 2, 4,pf);
        // Imprime o conteúdo, se existir, do arquivo informado
       // for(int i = 0 ;conteudo[i] != '\0' &&i < 100  ; i++)
           // printf("%c", conteudo[i]);
        printf("\nO CONTEÚDO DO ARQUIVO É:\n %s \n", conteudo);
        printf("\nO CONTEÚDO DO ARQUIVO É:\n %s \n", var2);

        fclose(pf);
}