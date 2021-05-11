#ifndef GRUPO_H
#define GRUPO_H

#include "Time.h"

typedef struct grupo
{
    int id;
    struct grupo *proximo;
    struct grupo *anterior;
} Grupo;

typedef struct grupoDescritor
{

    int tamanho;
    Grupo *primeiro;
    Grupo *ultimo;

} GrupoDescritor;

GrupoDescritor *criaGrupo();

int insereGrupoFim(GrupoDescritor *L, int id);

int mostraGrupos(GrupoDescritor *L);

int sorteiaGrupos(tipoDescritor *L, GrupoDescritor *G1, GrupoDescritor *G2);

int deletaGrupo(GrupoDescritor *G);

#endif