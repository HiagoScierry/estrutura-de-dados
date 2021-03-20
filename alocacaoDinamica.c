#include <stdio.h>
#include <stdlib.h>




int main() {
	
 int a, b, c, d;
 int *e, *f;
 
 a = 10;
 b = 8;
 c = 3;
 d = 1;
 
 e = (int *) malloc(sizeof(int));
 
 f = (int *) malloc(sizeof(int));
 
 printf("endereço de a: %p\n", &a);
 printf("endereço de b: %p\n", &b);
 printf("endereço de c: %p\n", &c);
 printf("endereço de d: %p\n", &d);
 printf("endereço de &e: %p\n", &e);
 printf("endereço de &f: %p\n\n", &f);
/*
 printf("conteudo a: %p\n", a);
 printf("conteudo b: %p\n", b);
 printf("conteudo c: %p\n", c);
 printf("conteudo d: %p\n\n", d);

 printf("endereco armazenado no ponteiro e: %p\n", e);
 printf("endereco armazenado no ponteiro f: %p\n\n", f);
 
 printf("conteudo do endereco para onde e aponta: %d\n", *e);
 printf("conteudo do endereco para onde f aponta: %d\n\n", *f);

 *e = 80;
 *f = 100; 
 printf("conteudo do endereco para onde e aponta: %d\n", *e);
 printf("conteudo do endereco para onde f aponta: %d\n\n", *f);

 e = f;
 printf("endereco armazenado no ponteiro e: %p\n", e);
 printf("endereco armazenado no ponteiro f: %p\n\n", f);
 printf("conteudo do endereco para onde e aponta: %d\n", *e);
 printf("conteudo do endereco para onde e aponta: %d\n\n", *f);
 
 e = &a;
 f = &c; 
 printf("endereco armazenado no ponteiro e: %p\n", e);
 printf("endereco armazenado no ponteiro f: %p\n\n", f);
 printf("conteudo do endereco para onde e aponta: %d\n", *e);
 printf("conteudo do endereco para onde f aponta: %d\n\n", *f);
*/ 
}