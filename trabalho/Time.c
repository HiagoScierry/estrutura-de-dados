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

// int editarTime(tipoDescritor *L, tipoTime *T, int pos)
// {
//     tipoNo *anterior, *temp;
//     int posatual = 1;

//     temp = (tipoNo *)malloc(sizeof(tipoNo));

//     temp = L->primeiro;

//     if (pos > L->quantidade || pos <= 0)
//     {
//         return -1;
//     }

//     while (temp == NULL)
//     {
//         if (pos == posatual)
//         {
//             //recebe as variaveis novas do time
//             *temp->time.nome = T->nome;
//             *temp->time.regiao = T->regiao;
//         }

//         anterior = temp;
//         temp = temp->proximo;

//         posatual++;
//     }

//     return 0;
// }

// int removerTime(tipoDescritor *L, int pos)
// {
//     tipoNo *atual, *anterior, *temp;
//     int posatual = 0;

//     if (pos > L->quantidade || pos <= 0)
//     {
//         return -1;
//     }

//     atual = L->primeiro;
//     while (atual == NULL)
//     {
//         if (pos == posatual)
//         {
//             temp = atual->proximo;
//             temp->anterior = anterior;
//             anterior->proximo = temp;
//         }

//         anterior = atual;
//         atual = atual->proximo;

//         posatual++;
//     }

//     L->quantidade--;
//     return 0;
// }
