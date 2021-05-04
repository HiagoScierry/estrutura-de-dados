#include <stdio.h>
#include <stdlib.h>

#define tamMaximo 15

typedef struct s_info {

  int chave;

} tipoInfo;


typedef struct s_Pilha {

  tipoInfo info;
  struct s_Pilha *proximo;
  
} tipoPilha;


void criaPilhaVazia(tipoPilha **p) {

  p = NULL;

}


int empilha(tipoPilha **p, tipoInfo inf) {

  tipoPilha *novoNo;
  
  novoNo = (tipoPilha *) malloc(sizeof(tipoPilha));
  if (novoNo == NULL)
	return -1;
  else {
	novoNo->info = inf;
	novoNo->proximo = *p;
	*p = novoNo;
    return 0;
  }
}


int desempilha(tipoPilha **p, tipoInfo *inf) {
	
  tipoPilha *temp;
  
  if (*p == NULL)
	return -1;
  else {
	temp = *p;
	inf->chave = temp->info.chave;
	*p = temp->proximo;
	free(temp);
	return 0;
  }
}


int main() {

  tipoPilha *pilha;
  tipoInfo info;
  int erro;
  
  criaPilhaVazia(&pilha);
  
  info.chave = 5;
  erro = empilha(&pilha, info);
  
  info.chave = 10;
  erro = empilha(&pilha, info);
  
  info.chave = 8;
  erro = empilha(&pilha, info);
  
  info.chave = 4;
  erro = empilha(&pilha, info);

  erro = desempilha(&pilha, &info);
  printf("%d\n", info.chave);

  erro = desempilha(&pilha, &info);
  printf("%d\n", info.chave);

  return 0;
  
}