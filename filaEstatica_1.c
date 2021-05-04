#include <stdio.h>
#include <stdlib.h>

#define tamMax 20

typedef struct s_info {
  int chave;
} info;


typedef struct s_fila {
  info vetor[tamMax];
  int posUltimo;
} tipoFila;


void criaFilaVazia(tipoFila *fila) {

  fila->posUltimo = -1;

}


int enfileira(tipoFila *fila, info inf) {

  if (fila->posUltimo == tamMax - 1)
    return -1;
  else {
	fila->posUltimo++;
	fila->vetor[fila->posUltimo] = inf;
    return 0;
  }
}


int desenfileira(tipoFila *fila, info *inf) {

  int i;

  if (fila->posUltimo == -1)
    return -1;
  else {
    *inf = fila->vetor[0];
	for(i = 0; i < fila->posUltimo - 1; i++)
	  fila->vetor[i] = fila->vetor[i+1];
	fila->posUltimo--;
	return 0;
  }
}


int main() {

  tipoFila fi;
  info item;
  
  criaFilaVazia(&fi);
  
  item.chave = 10;
  enfileira(&fi, item);
  
  item.chave = 8;
  enfileira(&fi, item);
  
  item.chave = 6;
  enfileira(&fi, item);
  
  item.chave = 4;
  enfileira(&fi, item);
  
  item.chave = 3;
  enfileira(&fi, item);
  
  desenfileira(&fi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  
  
  desenfileira(&fi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  

  return 0;
}