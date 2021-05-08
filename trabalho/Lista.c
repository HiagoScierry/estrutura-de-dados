#include <stdio.h>
#include <stdlib.h>

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
    L->primeiro = novoNo;
    L->quantidade++;

    return 0;
}

int insereFinal(tipoDescritor *L, tipoTime inf)
{
    tipoNo *novoNo, *anterior, *temp;

    novoNo = (tipoNo *)malloc(sizeof(tipoNo));

    if (novoNo == NULL)
        return -1;

    novoNo->time = inf;
    temp = L->primeiro;

    while (temp != NULL)
    {
        anterior = temp;
        temp = temp->proximo;
    }
    anterior->proximo = novoNo;
    L->ultimo = novoNo;
    L->quantidade++;

    return 0;
}

int inserePosicao(tipoDescritor *L, tipoTime inf, int pos)
{
    tipoNo *temp, *anterior, *novoNo;
    int posAtual = 1;

    temp = L->primeiro;

    while (posAtual < pos && temp != NULL)
    {
        anterior = temp;
        temp = temp->proximo;
        posAtual++;
    }

    if (temp == NULL || posAtual == pos)
    {
        novoNo = (tipoNo *)malloc(sizeof(tipoNo));
        novoNo->time = inf;
        if (pos == 1)
        {
            insereInicio(L, inf);
        }
        else if (pos > L->quantidade)
        {
            insereFinal(L, inf);
        }
        else
        {
            anterior->proximo = novoNo;
            novoNo->anterior = anterior;
            novoNo->proximo = temp;
            temp->anterior = novoNo;
            L->quantidade++;
        }

        return 0;
    }
    else
    {
        return -1;
    }
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
        return 0;
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

    L->primeiro = temp->proximo;

    free(temp);

    return 0;
}

int removeFim(tipoDescritor *L)
{
    tipoNo *temp;

    temp = L->ultimo;

    if (temp == NULL)
        return -1;

    L->ultimo = temp->anterior;

    free(temp);

    return 0;
}


int removeMeio(tipoDescritor *L, int Id){

    tipoNo *temp;

    temp = L->primeiro;

    if (temp == NULL) return -1;

    while (Id != temp->time.id)
    {
         temp = temp->proximo;
    }

    temp->anterior->proximo = temp->proximo;
    temp->proximo->anterior = temp->anterior;

    free(temp);
    
    return 0;

}