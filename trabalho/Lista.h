#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

#include "Time.h"

int insereInicio(tipoDescritor *L, tipoTime inf);

int insereFinal(tipoDescritor *L, tipoTime inf);

int inserePosicao(tipoDescritor *L, tipoTime inf, int pos);

int mostrarLista(tipoDescritor *L);

int proximoId(tipoDescritor *L);

int removeInicio(tipoDescritor *L);

int removeFim(tipoDescritor *L);

int copiaLista(tipoDescritor *L1, tipoDescritor *L2);

#endif