#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Time.h"
#include "Lista.h"

int insereInicio(tipoDescritor *L, tipoTime inf)
{
    tipoNo *novoNo;

    novoNo = (tipoNo *)malloc(sizeof(tipoNo));
    if (novoNo == NULL)
        return -1;

    novoNo->time = inf;
    novoNo->proximo = L->primeiro;

    if (L->primeiro != NULL)
    {
        L->primeiro->anterior = novoNo;
    }
    else
    {
        L->ultimo = novoNo;
    }

    novoNo->anterior = NULL;
    L->primeiro = novoNo;
    L->quantidade++;

    return 0;
}

int insereFinal(tipoDescritor *L, tipoTime inf)
{
    tipoNo *novoNo;

    if (L == NULL)
        return -1;

    if (L->primeiro == NULL)
        return insereInicio(L, inf);

    novoNo = (tipoNo *)malloc(sizeof(tipoNo));
    if (novoNo == NULL)
        return -1;

    novoNo->time = inf;
    novoNo->proximo = NULL;
    novoNo->anterior = L->ultimo;
    novoNo->anterior->proximo = novoNo;
    L->ultimo = novoNo;
    L->quantidade++;

    return 0;
}

int inserePosicao(tipoDescritor *L, tipoTime inf, int pos)
{
    tipoNo *novoNo, *aux;
    int posatual = 0;

    if (L->quantidade == 0 || pos == 0)
    {
        return insereInicio(L, inf);
    }

    if (pos == L->quantidade)
    {

        return insereFinal(L, inf);
    }

    for (aux = L->primeiro; aux != NULL; aux = aux->proximo)
    {
        if (pos == posatual)
        {

            break;
        }
        posatual++;
    }

    novoNo = (tipoNo *)malloc(sizeof(tipoNo));

    if (novoNo == NULL)
    {
        return -1;
    }

    novoNo->time = inf;
    aux->anterior->proximo = novoNo;
    novoNo->proximo = aux;
    novoNo->anterior = aux->anterior;
    aux->anterior = novoNo;

    return 0;
}

int mostrarLista(tipoDescritor *L)
{
    tipoNo *temp;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    while (temp != NULL)
    {
        printf("%i - ", temp->time.id);
        printf("%s - ", temp->time.nome);
        printf("%s \n", temp->time.regiao);

        temp = temp->proximo;
    }
    printf("\n");

    return 0;
}

int proximoId(tipoDescritor *L)
{
    tipoNo *temp;
    int maiorID;

    if (L->primeiro == NULL)
    {
        return 1;
    }

    temp = L->primeiro;
    maiorID = temp->time.id;
    temp = temp->proximo;

    while (temp != NULL)
    {
        if (temp->time.id > maiorID)
        {
            maiorID = temp->time.id;
        }

        temp = temp->proximo;
    }

    return maiorID + 1;
}

int removeInicio(tipoDescritor *L)
{
    tipoNo *temp;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    if (temp->proximo == NULL)
    {
        L->primeiro = NULL;
    }
    else
    {
        L->primeiro = temp->proximo;
        L->primeiro->anterior = NULL;
    }

    L->quantidade--;

    if (L->quantidade == 0)
    {
        L->primeiro = NULL;
        L->ultimo = NULL;
    }

    free(temp);

    return 0;
}

int removeFim(tipoDescritor *L)
{
    tipoNo *temp;

    temp = L->ultimo;

    if (temp == NULL)
        return -1;

    if (temp->anterior == NULL)
    {
        L->ultimo = NULL;
    }
    else
    {
        L->ultimo = temp->anterior;
        L->ultimo->proximo = NULL;
    }

    L->quantidade--;

    if (L->quantidade == 0)
    {
        L->primeiro = NULL;
        L->ultimo = NULL;
    }

    free(temp);

    return 0;
}

int copiaLista(tipoDescritor *L1, tipoDescritor *L2)
{

    tipoNo *temp;
    tipoTime timeProv;

    if (L1 == NULL)
        return -1;

    temp = L1->primeiro;

    if (temp == NULL || L1->quantidade == 0)
        return -1;

    while (temp != NULL)
    {
        timeProv.id = temp->time.id;
        strcpy(timeProv.nome, temp->time.nome);
        strcpy(timeProv.regiao, temp->time.regiao);
        insereFinal(L2, timeProv);
        temp = temp->proximo;
    }

    return 0;
}
