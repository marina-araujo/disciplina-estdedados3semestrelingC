#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void imprimir(int *xi, int *ptr_xi) {
    printf("Valor de xi = %d \n", *xi);
    printf("Valor de &xi = %p \n", xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi);
}
	
int main(int argc, char** argv) {
	int xi;
    int *ptr_xi;

    xi = 10;
    ptr_xi = &xi;
    xi = 20;
    *ptr_xi = 30;
    
    printf("Valor de xi = %d \n", xi);
    printf("Valor de &xi = %p \n", &xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi);
    
    printf("-----------------------------------------\n\n");

    int x2;
	int *ptr2;
	ptr2 = &x2;
    printf("Endereco: %p\n\n", ptr2);
    ptr2 = (int *) malloc(sizeof (int));
    printf("Endereco: %p \nValor: %d\n\n", ptr2, *ptr2);
    x2 = 10;
    printf("Endereco: %p \nValor: %d\n\n", ptr2, *ptr2);
    *ptr2 = 20; // com malloc o ponteiro *ptr2 passa a apontar para um endereço diferente do de x2
    printf("Endereco: %p \nValor de x2: %d\nValor de *ptr2: %d\n\n", ptr2, x2, *ptr2);
    
    printf("-----------------------------------------\n\n");
    
    int *ptr3;
    printf("Endereco: %p\n\n", ptr3);
    ptr3 = (int *) malloc(sizeof (int));
    printf("Endereco: %p \nValor: %d\n\n", ptr3, *ptr3);
    *ptr3 = 10;
    printf("Endereco: %p \nValor: %d\n\n", ptr3, *ptr3);
    int x3;
    x3 = 20;
    ptr3 = &x3;
    printf("Endereco: %p \nValor: %d\n\n", ptr3, *ptr3);
    
    
    


    //imprimir(&xi, ptr_xi);  // Passando o endereço de xi
    return 0;
}
