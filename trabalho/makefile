compilaTime:
	gcc -c Time.c -o time.o

compilaLista:
	gcc -c Lista.c -o lista.o


compilaGrupo:
	gcc -c Grupo.c -o grupo.o


compilaMain: 
	gcc main.c time.o lista.o grupo.o -o main && clear && ./main 

compila: compilaTime compilaLista compilaGrupo compilaMain