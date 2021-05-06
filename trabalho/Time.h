#ifndef TIME_H
#define TIME_H


#include <stdio.h>
#include <stdlib.h>

typedef struct s_time
{
    int id;
    char nome[20];
    char regiao[20];
} tipoTime;

typedef struct s_lista
{
    tipoTime time;
    struct s_lista *proximo;
    struct s_lista *anterior;

} tipoNo;

typedef struct s_descritor
{

    int quantidade;
    tipoNo *primeiro;
    tipoNo *ultimo;

} tipoDescritor;


tipoDescritor *criarLista();

int criarTime(tipoDescritor *L, tipoTime inf);

int editarTime(tipoDescritor *L, tipoTime *T,int pos);

int removerTime(tipoDescritor *L, int pos);

#endif