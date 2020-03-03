//
// Created by marco on 3/3/20.
//
#include "ficheiros.h"

#include <stdio.h>


void atualizarTab (char *fileName, int m, int n)
{
    FILE *fptr;
    char c;
    fptr = fopen("temp","a");
    if(fptr == NULL) printf("NAO EXISTE\n");
    fscanf(fptr, "%c",&c);
    fprintf(fptr,"%d",'a');
    printf("hell %d\n",c);
    fclose(fptr);
}