#include <stdio.h>
#include <stdlib.h>

#define tamMax 20

typedef struct s_info {
  int chave;
} info;


typedef struct s_pilha {
  info vetor[tamMax];
  int posUltimo;
} tipoPilha;


void criaPilhaVazia(tipoPilha *p) {

  p->posUltimo = -1;

}


int empilha(tipoPilha *p, info inf) {

  if (p->posUltimo == tamMax - 1)
    return -1;
  else {
	p->posUltimo++;
	p->vetor[p->posUltimo] = inf;
    return 0;
  }
}


int desempilha(tipoPilha *p, info *inf) {

  int i;

  if (p->posUltimo == -1)
    return -1;
  else {
    *inf = p->vetor[p->posUltimo];
	p->posUltimo--;
	return 0;
  }
}


int main() {

  tipoPilha pi;
  info item;
  int erro;
  
  criaPilhaVazia(&pi);
  
  item.chave = 10;
  erro = empilha(&pi, item);
  
  item.chave = 8;
  erro = empilha(&pi, item);
  
  item.chave = 6;
  erro = empilha(&pi, item);
  
  item.chave = 4;
  erro = empilha(&pi, item);
  
  item.chave = 3;
  erro = empilha(&pi, item);
  
  erro = desempilha(&pi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  
  
  erro = desempilha(&pi, &item);
  printf("Item desenfileirado: %d\n", item.chave);  

  return 0;
}