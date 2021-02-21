#include <stdio.h>
#include <stdlib.h>

#define tamMaximo 15

typedef struct s_info
{
    int chave;
} tipoInfo;

typedef struct s_lista
{
    tipoInfo elementos[tamMaximo];
    int posUltimo;
} tipoLista;

void fazVazia(tipoLista *l)
{
    l->posUltimo = -1;
}

int insereLocalEscolhido(tipoLista *l, tipoInfo info, int pos)
{
    int retorno = 0;
    int realPos = pos - 1;

    if (l->posUltimo == tamMaximo - 1)
    {
        retorno = -1;
    }
    else
    {
        l->posUltimo++;
        for (int i = l->posUltimo; i > realPos; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[realPos] = info;
    }

    return retorno;
}

int insereInicio(tipoLista *l, tipoInfo info)
{
    int retorno = 0;

    if (l->posUltimo == tamMaximo - 1)
    {
        retorno = -1;
    }
    else
    {
        l->posUltimo++;
        for (int i = l->posUltimo; i > 0; i--)
        {
            l->elementos[i] = l->elementos[i - 1];
        }

        l->elementos[0] = info;
    }

    return retorno;
}

int insereFinal(tipoLista *l, tipoInfo info)
{

    int retorno = 0;

    if (l->posUltimo == tamMaximo - 1)
    {
        retorno = -1;
    }
    else
    {
        l->posUltimo++;
        l->elementos[l->posUltimo] = info;
    }

    return retorno;
}

int retirarElementoEscolhido(tipoLista *l, tipoInfo info, int pos)
{
}

void imprimeLista(tipoLista l)
{
    int pos = 0;
    while (pos <= l.posUltimo)
    {
        printf("%d,", l.elementos[pos].chave);
        pos++;
    }
    printf("\n");
}

int main()
{
    tipoLista lista;
    tipoInfo info;

    fazVazia(&lista);

    info.chave = 5;
    insereInicio(&lista, info);

    info.chave = 10;
    insereInicio(&lista, info);

    info.chave = 8;
    insereInicio(&lista, info);

    info.chave = 22;
    insereLocalEscolhido(&lista, info, 2);

    imprimeLista(lista);

    return 0;
}