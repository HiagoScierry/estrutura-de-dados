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

    if (novoNo == NULL)
        return -1;

    novoNo->id = id;

    if (L->tamanho == 0)
    {
        L->primeiro = novoNo;
        L->ultimo = novoNo;
        novoNo->proximo = NULL;
        novoNo->anterior = NULL;
        return 0;
    }

    novoNo->proximo = NULL;
    novoNo->anterior = L->ultimo;
    L->ultimo->proximo = novoNo;
    L->ultimo = novoNo;

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

int sorteiaGrupos(tipoDescritor *L, GrupoDescritor *G, int N)
{
    int aleatorio;
    tipoNo *temp;
    int pos;

    printf("quantidade : %i\n", L->quantidade);

    if (L == NULL || G == NULL || N <= 0)
        return -1;

    srand(time(NULL));

    for (int i = 0; i < N; i++)
    {
        aleatorio = rand() % (L->quantidade);
        printf("aleatorio: %i\n", aleatorio);

        temp = L->primeiro;
        pos = 0;

        printf("%p\n", temp);
        while (temp != NULL && pos != aleatorio)
        {
            temp = temp->proximo;
            pos++;
        }

        printf("%i\n", temp->time.id);

        if (temp == NULL)
            return -1;

        // insereGrupoFim(G, temp->time.id);
        removerTime(L, temp->time.id);
        printf("alguma coisa");
    }

    return 0;
}
