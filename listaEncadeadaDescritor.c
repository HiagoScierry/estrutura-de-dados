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


typedef struct s_descritor {

  int numElementos;
  tipoNo *primElemento;
  
} tipoDescritor;


void criaListaVazia(tipoDescritor *L) {

  L->numElementos = 0;
  L->primElemento = NULL;
}

int insereInicio(tipoDescritor *L, tipoInfo inf) {

  tipoNo *novoNo;
  
  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = L->primElemento;
	L->numElementos++;
	L->primElemento = novoNo;
	return 0;
  }
  
  
}

int insereFinal(tipoDescritor *L, tipoInfo inf) {

  tipoNo *novoNo, *anterior, *temp;

  novoNo = (tipoNo *) malloc(sizeof(tipoNo));
  if (novoNo == NULL)
    return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = NULL;
	if (L->primElemento == NULL)  // Lista estava vazia
	  L->primElemento = novoNo;
    else {
	  temp = L->primElemento;
	  while (temp != NULL) {
	    anterior = temp;
	    temp = temp->proximo;
	  }
	  anterior->proximo = novoNo;
	}
	L->numElementos++;
	return 0;
  }
}


void fazListaVazia(tipoDescritor *L) {

// usar o comando free(ponteiro)

  tipoNo *temp;
  
  while (L->primElemento != NULL) {
	temp = L->primElemento;
	L->primElemento = L->primElemento->proximo;
	free(temp);
  }
  L->numElementos = 0;

}


int inserePosicao(tipoDescritor *L, tipoInfo info, int pos) {

  tipoNo *temp, *anterior, *novoNo;
  int posAtual;

  temp = L->primElemento;
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
	  L->primElemento = novoNo;
	} else {
      anterior->proximo = novoNo;
	  novoNo->proximo = temp;
	}
	L->numElementos++;
	return 0;
  } else
    return -1;

}


int numElementosLista(tipoDescritor L) {
	
  return L.numElementos;

}


void mostraLista(tipoDescritor L) {

  tipoNo *temp;
  
  temp = L.primElemento;
  while (temp != NULL) {
	printf("%d, ", temp->info.chave);
	temp = temp->proximo;
  }
  printf("\n");
  
}


int main() {

  tipoDescritor Lista;
  tipoInfo info;
  
  criaListaVazia(&Lista);
  
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
