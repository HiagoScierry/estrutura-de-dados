#include <stdio.h>
#include <stdlib.h>

#define tamMax 5

typedef struct s_info {
  int chave;
} info;


typedef struct s_fila {
  info vetor[tamMax];
  int numElementos;
  int posInsere;
  int posRemove;
} tipoFila;


void criaFilaVazia(tipoFila *fila) {

  fila->numElementos = 0;
  fila->posInsere = 0;
  fila->posRemove = 0;

}


int enfileira(tipoFila *fila, info inf) {

  if (fila->numElementos == tamMax)
    return -1;
  else {
    fila->numElementos++;
	fila->vetor[fila->posInsere] = inf;
//    printf("%d     %d    %d     %d\n", fila->vetor[fila->posInsere].chave, fila->posRemove, fila->posInsere, fila->numElementos);
	if (fila->posInsere == tamMax - 1)
	  fila->posInsere = 0;
    else
	  fila->posInsere++;
    return 0;
  }
}


int desenfileira(tipoFila *fila, info *inf) {

  int i;

//  printf("%d     %d\n", fila->posRemove, fila->posInsere);
  if (fila->numElementos == 0)
    return -1;
  else {
    inf->chave = fila->vetor[fila->posRemove].chave;
//	printf("%d\n", inf->chave);
	if (fila->posRemove == tamMax - 1)
	  fila->posRemove = 0;
    else
	  fila->posRemove++;
    fila->numElementos--;
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
  
  item.chave = 6;
  erro = enfileira(&fi, item);
  
  item.chave = 4;
  erro = enfileira(&fi, item);
  
  item.chave = 3;
  erro = enfileira(&fi, item);
  
  
//  printf(" \n\n\n\");
  
  
  
  erro = desenfileira(&fi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  
  
  erro = desenfileira(&fi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  

  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  

  item.chave = 15;
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

  erro = desenfileira(&fi, &item);
  if (erro == -1)
	printf("Fila Vazia!!\n");
  else
    printf("Item desenfileirado: %d\n", item.chave);  


  return 0;
}