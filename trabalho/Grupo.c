#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Time.h"
#include "Lista.h"
#include "Grupo.h"

GrupoDescritor *criaGrupo()
{
    GrupoDescritor *grupo = (GrupoDescritor *)malloc(sizeof(GrupoDescritor));

    if (grupo == NULL)
    {
        return NULL;
    }

    grupo->primeiro = NULL;
    grupo->ultimo = NULL;
    grupo->tamanho = 0;

    return grupo;
}

int insereGrupoFim(GrupoDescritor *L, int id)
{

    Grupo *novoNo;

    novoNo = (Grupo *)malloc(sizeof(Grupo));

    if (novoNo == NULL || L == NULL)
        return -1;

    novoNo->id = id;

    if (L->primeiro == NULL)
    {
        L->primeiro = novoNo;
        L->ultimo = novoNo;
        novoNo->proximo = NULL;
        novoNo->anterior = NULL;
        L->tamanho++;

        return 0;
    }

    novoNo->proximo = NULL;
    novoNo->anterior = L->ultimo;
    L->ultimo->proximo = novoNo;
    L->ultimo = novoNo;
    L->tamanho++;

    return 0;
}

int mostraGrupos(GrupoDescritor *L)
{
    Grupo *temp;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    while (temp != NULL)
    {
        printf("%i ", temp->id);

        temp = temp->proximo;
    }
    printf("\n");

    return 0;
}

int deletaGrupo(GrupoDescritor *G)
{

    Grupo *temp;

    if (G == NULL)
    {
        return -1;
    }

    if (G->tamanho == 0)
    {
        return -1;
    }

    temp = G->primeiro;

    while (temp->proximo != NULL)
    {
        temp = temp->proximo;
        free(temp->anterior);
    }

    free(temp);

    G->primeiro = NULL;
    G->ultimo = NULL;
    G->tamanho = 0;
    return 0;
}

int sorteiaGrupos(tipoDescritor *L, GrupoDescritor *G1, GrupoDescritor *G2)
{
    int aleatorio, pos, tam;
    tipoNo *temp;

    if (L == NULL)
        return -1;

    if (L->quantidade == 0)
        return -1;

    if (G1 == NULL || G2 == NULL)
        return -1;

    if (G1->tamanho != 0)
    {
        printf("grupo 1 com coisa");
        deletaGrupo(G1);
    }

    if (G2->tamanho != 0)
    {
        deletaGrupo(G2);
    }

    srand(time(NULL));

    while (L->primeiro != NULL)
    {
        aleatorio = rand() % L->quantidade + 1;
        pos = 1;
        temp = L->primeiro;
        printf("%p\n", temp);

        while (pos != aleatorio && temp != NULL)
        {
            temp = temp->proximo;
            pos++;
        }

        if (temp == NULL)
            return -1;

        if (L->quantidade % 2 == 0)
        {
            insereGrupoFim(G1, temp->time.id);
        }
        else
        {
            insereGrupoFim(G2, temp->time.id);
        }

        removerTime(L, temp->time.id);
    }

    return 0;
}
