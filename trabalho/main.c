#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Time.h"
#include "Lista.h"

int main(int argc, char const *argv[])
{
    int menuescolha;
    int ret;

    tipoDescritor *descritorTimes;
    tipoTime timeProv = {1, "hiago", "linhares"};
    tipoTime timeProv2 = {2, "dav", "sm"};
    tipoTime timeProv3 = {3, "thais", "sm"};

    descritorTimes = criarLista();

    while (menuescolha != 7)
    {
        printf("----------------MENU------------------\n");
        printf("1 - Cadastrar time\n");
        printf("2 - Editar time\n");
        printf("3 - Remover time\n");
        printf("4 - Imprimir times\n");
        printf("5 - Sortear grupos\n");
        printf("6 - Imprimir grupos\n");
        printf("7 - sair\n");

        printf("-------------------------------------------\n");
        printf("Esconlha uma opção : ");

        scanf("%i", &menuescolha);

        if (menuescolha == 1)
        {

            criarTime(descritorTimes, timeProv);
            criarTime(descritorTimes, timeProv2);
            criarTime(descritorTimes, timeProv3);

            mostrarLista(descritorTimes);
        }
        else
        {
            printf("Botao errado");
        }

        return 0;
    }
}