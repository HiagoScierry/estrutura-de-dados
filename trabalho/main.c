#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Time.h"
#include "Lista.h"

int main(int argc, char const *argv[])
{
    int menuescolha;

    tipoDescritor *descritorTimes;
    tipoTime timeProv = {0, "", "l"};
    int idProv;

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

        switch (menuescolha)
        {
        case 1:
            printf("Digite o nome do time :");
            scanf("%s", timeProv.nome);

            printf("Digite o nome da regiao :");
            scanf("%s", timeProv.regiao);

            criarTime(descritorTimes, timeProv);

            system("clear");

            break;

        case 2:
            system("clear");
            mostrarLista(descritorTimes);
            printf("selecione o ID para editar");
            scanf("%i", &idProv);

            printf("Digite o novo nome do time :");
            scanf("%s", timeProv.nome);

            printf("Digite o novo nome da regiao :");
            scanf("%s", timeProv.regiao);

            editarTime(descritorTimes, timeProv, idProv);
            break;

        case 3:

            system("clear");
            printf("selecione o ID para remover");
            scanf("%i", &idProv);
            removerTime(descritorTimes, idProv);
            break;

        case 4:

            system("clear");

            mostrarLista(descritorTimes);
            break;
        default:
            break;
        }
    }

    return 0;
}