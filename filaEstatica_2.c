#include <stdio.h>
#include <stdlib.h>

#define tamMax 20

typedef struct s_info {
  int chave;
} info;


typedef struct s_fila {
  info vetor[tamMax];
  int posPrimeiro;
  int posUltimo;
} tipoFila;


void criaFilaVazia(tipoFila *fila) {

  fila->posPrimeiro = -1;
  fila->posUltimo = 0;

}


int enfileira(tipoFila *fila, info inf) {

  if (fila->posUltimo == tamMax - 1)
    return -1;
  else {
	if (fila->posPrimeiro == -1)
      fila->posPrimeiro++;
	fila->vetor[fila->posUltimo] = inf;
	fila->posUltimo++;
//    printf("%d          %d           %d\n", fila->posPrimeiro, fila->posUltimo, fila->vetor[fila->posUltimo].chave);
    return 0;
  }
}


int desenfileira(tipoFila *fila, info *inf) {

  int i;

//  printf("%d      %d\n", fila->posPrimeiro, fila->posUltimo);
  if (fila->posUltimo == fila->posPrimeiro)
    return -1;
  else {
    inf->chave = fila->vetor[fila->posPrimeiro].chave;
	fila->posPrimeiro++;
	return 0;
  }
}


int main() {

  tipoFila fi;
  info item;
  int erro;
  
  criaFilaVazia(&fi);
  
  item.chave = 10;
  erro = enfileira(&fi, item);
  
  item.chave = 8;
  erro = enfileira(&fi, item);

  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  
  
  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  

  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  

  item.chave = 6;
  erro = enfileira(&fi, item);

  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  

  return 0;
}