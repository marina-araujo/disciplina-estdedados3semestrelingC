#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int *p;
	p = (int *) malloc(sizeof(int));
	if(p == NULL){
		printf("Erro!\n");
	} else {
		*p = 10;
		printf("p: %d\n", *p);
		printf("o endereco de p eh: %d\n", p);
		//free(p);
	}
	int *x;
	x = (int *) malloc(sizeof(int));
	if(x == NULL){
		printf("Erro!\n");
	} else {
		*x = 30;
		printf("x: %d\n", *x);
		printf("o endereco de x eh: %d\n", x);
		free(p);
		free(x);
	}
	
	return 0;
}
