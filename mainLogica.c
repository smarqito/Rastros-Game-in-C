//
// Created by marco on 3/3/20.
//

#include <stdio.h>
#include <string.h>
#include "mainLogica.h"
#include "modules/interface/interface.h"
#include "modules/data.h"
#include "globals.h"
#include "modules/coordenada.h"

void print_array (char *a, int dim)
{
    for (int i=0; a[i] != '\0' && i<dim;i++)
        printf("%c",a[i]);
    printf("\n");
}
/* verifica se a instrução é válida tendo como base uma array de strings (respostas possíveis)
 * copia a instrução para uma nova array específica para tal
 * elimina os espaços até encontrar o argumento da instrução
 * copia o argumento para uma nova array
 * conforme a instrução, executa a função apropriada
 * */

void executaInstr (char ip[]) {
    char instr[11], arg[MAXCHAR];
    int i,c=0;
    char opcoes[6][11] = {
            "coordenada",
            "gr",
            "ler",
            "movs",
            "jog",
            "pos"
    };
    ESTADO e;
    initState(&e);

    for(i=0;ip[i]==' '; i++);
    //copia a instrução
    for(i; ip[i] != ' '; i++)
        instr[c++]=ip[i];
    instr[c]='\0';
    //elimina os espaços até à instrução
    for(i;ip[i] == ' ';i++);
    //copia o argumento
    c=0;
    for(i; ip[i] != '\0'; i++)
        arg[c++]=ip[i];
    arg[c]='\0';
    for(i=0; strcmp(instr,opcoes[i]) != 0 && i<6;i++);
    switch (i)
    {
        case 0:
            printf("func coordenada\n");
            if(!validaCoord(arg)) break;
            print_array(arg,2);
            mostrarTabuleiro(&e);
            break;
        case 1:
            printf("func gravar\n");
            print_array(arg,MAXCHAR);
            break;
        case 2:
            printf("func ler\n");
            print_array(arg,MAXCHAR);
            break;
        case 3:
            printf("func movs\n");
            print_array(arg,MAXCHAR);
            break;
        case 4:
            printf("func jogada do bot\n");
            print_array(arg,MAXCHAR);
            break;
        case 5:
            printf("func pos antiga\n");
            print_array(arg,MAXCHAR);
            break;
        default:
            printf("Opção inválida!\n");
            print_array(arg,2);
            break;
    }
}

//verifica se a string é para sair do jogo @Bool
int sair (char ip[]){
    int i;
    for (i=0; ip[i] != '\0';i++)
        ;
    (i==1) ?
    ip[0] == 'Q' ? (i=1) : (i=0)
           : (i=0);
    return i;
}