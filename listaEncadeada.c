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


void criaListaVazia(tipoNo **L) {
	
  *L = NULL;
}

int insereInicio(tipoNo **L, tipoInfo inf) {

  tipoNo *novoNo;
  
  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = *L;
	*L = novoNo;
	return 0;
  }
  
  
}

int insereFinal(tipoNo **L, tipoInfo inf) {

  tipoNo *novoNo, *anterior, *temp;

  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = NULL;
	if (*L == NULL)
	  *L = novoNo;
    else {
	  temp = *L;
	  while (temp != NULL) {
	    anterior = temp;
	    temp = temp->proximo;
	  }
	  anterior->proximo = novoNo;
	}
	return 0;
  }
}


void fazListaVazia(tipoNo **L) {

// usar o comando free(ponteiro)

  tipoNo *temp;
  
  while (*L != NULL) {
	temp = *L;
	*L = (*L)->proximo;
	free(temp);
  }

}

int numElementosLista(tipoNo *L) {
	
  int numElem;
  tipoNo *temp;
  
  numElem = 0;
  temp = L;
  while (temp != NULL) {
	numElem++;
	temp = temp->proximo;
  }

  return numElem;

}

int inserePosicao(tipoNo **L, tipoInfo info, int pos) {

  tipoNo *temp, *anterior, *novoNo;
  int posAtual;

  temp = *L;
  posAtual = 1;
  while (posAtual < pos && temp != NULL) {
	anterior = temp;
    temp = temp->proximo;
	posAtual++;
  }
  if (temp == NULL || posAtual == pos) {
	novoNo = (tipoNo *) malloc(sizeof(tipoNo));
	novoNo->info = info;
	if (pos == 1) {
	  novoNo->proximo = NULL;
	  *L = novoNo;
	} else {
      anterior->proximo = novoNo;
	  novoNo->proximo = temp;
	}
	return 0;
  } else
    return -1;
  
}


void mostraLista(tipoNo *L) {

  tipoNo *temp;
  
  temp = L;
  while (temp != NULL) {
	printf("%d, ", temp->info.chave);
	temp = temp->proximo;
  }
  printf("\n");
  
}

int main() {

  tipoNo *Lista;
  tipoInfo info;
  
  criaListaVazia(&Lista);

  info.chave = 5;
  insereInicio(&Lista, info);

  info.chave = 8;
  insereInicio(&Lista, info);

  info.chave = 3;
  insereFinal(&Lista, info);

  info.chave = 4;
  inserePosicao(&Lista, info, 2);

  mostraLista(Lista);
  
  return 0;
}  
