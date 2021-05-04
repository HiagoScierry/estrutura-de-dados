#include <stdio.h>
#include <stdlib.h>

#define tamMaximo 15

typedef struct s_info {

  int chave;

} tipoInfo;


typedef struct s_no {

  tipoInfo info;
  struct s_no *proximo;

} tipoNo;


void criaFilaVazia(tipoNo **F) {
	
  *F = NULL;
}

int enfileira(tipoNo **F, tipoInfo inf) {

  tipoNo *novoNo;
  
  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = *F;
	*F = novoNo;
	return 0;
  }
}


tipoInfo *desenfileira(tipoNo **F, tipoInfo *inf) {
	
  tipoNo *ant, *antant, *atual;
  
  atual = *F;
  ant = NULL;
  antant = NULL;
  while (atual != NULL) {
	antant = ant;
	ant = atual;
	atual = atual->proximo;
  };
  if (ant == NULL)
	return NULL;
  else {
	inf->chave = (ant->info).chave;
	if (antant == NULL) {
	  free(ant);
	  *F = NULL;
	} else {
	  free(ant);
	  antant->proximo = NULL;
	}
	return retorno;
  }
}


void fazFilaVazia(tipoNo **F) {

// usar o comando free(ponteiro)

  tipoNo *temp;
  
  while (*F != NULL) {
	temp = *F;
	*F = (*F)->proximo;
	free(temp);
  }

}

int main() {

  tipoNo *Fila;
  tipoInfo info;
  int erro;
  
  criaFilaVazia(&Fila);

  info.chave = 5;
  erro = enfileira(&Fila, info);

  info.chave = 8;
  erro = enfileira(&Fila, info);

  info.chave = 3;
  erro = enfileira(&Fila, info);

  info.chave = 4;
  erro = enfileira(&Fila, info);
  
  erro = desenfileira(&Fila, &info);
  if (erro < 0)
	printf("Fila vazia|||\n");
  else
	printf("%d \n", info.chave);
  
  erro = desenfileira(&Fila, &info);
  if (erro < 0)
	printf("Fila vazia|||\n");
  else
	printf("%d \n", info.chave);
  
  erro = desenfileira(&Fila, &info);
  if (erro < 0)
	printf("Fila vazia|||\n");
  else
	printf("%d \n", info.chave);
  
  erro = desenfileira(&Fila, &info);
  if (erro < 0)
	printf("Fila vazia|||\n");
  else
	printf("%d \n", info.chave);
  
  erro = desenfileira(&Fila, &info);
  if (erro < 0)
	printf("Fila vazia|||\n");
  else
	printf("%d \n", info.chave);
  return 0;
}  
