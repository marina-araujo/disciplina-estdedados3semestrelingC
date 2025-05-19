#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int *p;
int x;

int main(int argc, char** argv) {
	x = 10;
	p = &x;
	printf("O valor de x eh: %d\n", x);
	printf("O valor de p eh: %d\n", p);
	x = 20;
	printf("O valor de x eh: %d\n", x);
	*p = 30;
	printf("O valor de x eh: %d\n", x);
	return 0;
}
