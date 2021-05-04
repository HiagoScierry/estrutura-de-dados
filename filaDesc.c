#include <stdio.h>
#include <stdlib.h>

typedef struct s_info {

  int chave;

} tipoInfo;


typedef struct s_no {

  tipoInfo info;
  struct s_no *proximo;

} tipoNo;


typedef struct s_desc {

  tipoNo *inicio;
  tipoNo *fim;

} tipoDescritor;


void criaFilaVazia(tipoDescritor *F) {

  F->inicio = NULL;
  F->fim = NULL;
}


int enfileira(tipoDescritor *F, tipoInfo info) {

  tipoNo *novoNo;

  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = info;
	novoNo->proximo = NULL;
	if (F->inicio == NULL)
	  F->inicio = novoNo;
	else
	  F->fim->proximo = novoNo;
	F->fim = novoNo;
	return 0;
  }
}


int desenfileira(tipoDescritor *F, tipoInfo *info) {
	
  tipoNo *temp;
  
  if (F->inicio == NULL)
	return -1;
  else {
	temp = F->inicio;
	info->chave = temp->info.chave;
	F->inicio = temp->proximo;
	free(temp);
    return 0;
  }
}

int main() {

  tipoDescritor Fila;
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
