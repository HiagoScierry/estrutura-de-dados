#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Time.h"
#include "Lista.h"

tipoDescritor *criarLista()
{
    tipoDescritor *descritor = (tipoDescritor *)malloc(sizeof(tipoDescritor));

    if (descritor == NULL)
        return NULL;

    descritor->primeiro = NULL;
    descritor->ultimo = NULL;
    descritor->quantidade = 0;

    return descritor;
}

int criarTime(tipoDescritor *L, tipoTime inf)
{
    tipoNo *temp;
    int pos = 0;

    if (L == NULL)
    {
        return -1;
    }

    temp = L->primeiro;
    inf.id = proximoId(L);

    while (temp != NULL)
    {

        if (strcmp(inf.nome, temp->time.nome) <= 0)
        {
            break;
        }
        temp = temp->proximo;
        pos++;
    }

    inserePosicao(L, inf, pos);

    return 0;
}

int editarTime(tipoDescritor *L, tipoTime T, int id)
{
    tipoNo *temp;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    while (temp->time.id != id)
    {

        if (temp == NULL)
            return -1;

        temp = temp->proximo;
    }

    T.id = id;
    temp->time = T;

    return 0;
}

int removerTime(tipoDescritor *L, int id)
{
    tipoNo *temp;
    int posatual = 0;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    while (temp != NULL)
    {
        if (id == temp->time.id)
        {
            break;
        }

        temp = temp->proximo;
        posatual++;
    }

    if (posatual + 1 == L->quantidade)
        return removeFim(L);

    if (posatual == 0)
        return removeInicio(L);

    temp->anterior->proximo = temp->proximo;
    temp->proximo->anterior = temp->anterior;
    L->quantidade--;
    free(temp);

    return 0;
}
