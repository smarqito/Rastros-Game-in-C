//
// Created by marco on 3/9/20.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpretador.h"
#include "../logica/logica.h"
#include "../logica/bot.h"
#include "interface.h"

int instrucao (char *instr) {
    int i=0;
    while(instr[i++]) if (instr[i] == '\n') instr[i] = '\0';
    char opcoes[MAX_INSTR][11] = {
            "coordenada",
            "gr",
            "ler",
            "movs",
            "jog",
            "pos",
            "ajuda",
            "Q"
    };

    for(i=0; i<MAX_INSTR && strcmp(opcoes[i],instr);i++);
    return (i==MAX_INSTR) ? 0 : (i+1);
}

int interpretador (ESTADO *e) {
    char linha[BUF_SIZE];
    char col[2], lin[2], espaco[2] = " ";
    char *instr, *arg;
    int iinstr;
    if((iinstr=verificaFim(e))) {
        printf("Venceu o jogador %d.\n",iinstr);
        return 1;
    }
    printf("Diga-nos a sua instrucao:\n");
    //lê uma linha do teclado
    if(fgets(linha,BUF_SIZE,stdin) == NULL)
        return 0;
    //divide o input em instrução e argumento
    instr = strtok(linha,espaco);
    arg = strtok(NULL,espaco);
    //caso a instrução não seja válida, pede nova função
    if (!(iinstr = instrucao(instr))) {
        printf("Opcao invalida!");
        interpretador(e);
        return 0;
    }
    switch (iinstr)
    {
        case 1:
            if(strlen(arg) == 3 && sscanf(arg, "%[a-h]%[1-8]", col, lin) == 2) {
                COORDENADA coord = {*lin - '1', *col - 'a'};
                jogar(e,coord);
                mostrarTabuleiro(e);
            } else {
                printf("Coordenada inválida. Tente novamente.\n");
            }
            interpretador(e);
            break;
        case 2:
            gravarJogo(e,arg);
            break;
        case 3:
            lerJogo(e,arg);
            break;
        case 4:
            lerMovimentos(e);
            break;
        case 5:
            jogaBot(e);
            break;
        case 6:
            mostraPos(e,arg);
            break;
        case 7:
            printf("\n%-25s Descrição","Instruções");
            printf("\n%-23s permite efetuar uma jogada na coordenada ##. Exemplo: coordenada d4.\n","coordenada ##");
            printf("%-23s gravar o estado atual do jogo num ficheiro.\n","gr nome_do_ficheiro");
            printf("%-23s ler o estado de um jogo a partir de um ficheiro.\n","ler nome_do_ficheiro");
            printf("%-23s imprimir a lista de movimentos do jogo atual.\n","movs");
            printf("%-23s pedir ajuda ao bot para escolher a jogada atual.\n","jog");
            printf("%-23s visualizar uma posição anterior através do seu número.\n","pos numero_da_jogada");
            printf("%-23s sair do jogo.\n\n", "Q");
            interpretador(e);
            break;
        case 8:
            printf("Obrigado por jogar connosco! Até à próxima.\n");
            break;
        default:
            printf("Opção inválida! \n");
            break;
    }

    return 1;
}