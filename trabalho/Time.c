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
    int ordem, posAtual = 1;

    inf.id = proximoId(L);

    if (L->quantidade == 0)
    {
        insereInicio(L, inf);
        return 0;
    }
    else
    {

        temp = L->primeiro;

        do
        {
            ordem = strcmp(temp->time.nome, inf.nome);
            temp = temp->proximo;

        } while (ordem <= 0 && temp != NULL);

        if (L->quantidade > posAtual)
        {
            insereFinal(L, inf);
        }
        else
        {
            inserePosicao(L, inf, posAtual);
        }

        return 0;
    }
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

    tipoNo *temp, *anterior;

    temp = L->primeiro;

    if (temp == NULL)
        return -1;

    while (temp != NULL)
    {
        if (id ==temp->time.id)
        {

            break;
        }

        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL)
        return -1;

    temp = temp->proximo;
    anterior->proximo = temp;
    temp->anterior = anterior;

    L->quantidade--;

    if(temp->anterior == NULL){
        L->primeiro = temp;
    } else if(temp->proximo == NULL){
        L->ultimo = temp;
    }


    return 0;
}
