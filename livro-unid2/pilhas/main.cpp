// bibliotecas:
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// constantes:
#define tamanho 10

// estrutura da pilha:
struct tpilha {
	int dados[tamanho];
	int ini;
	int fim;
};

// vari�veis globais:
struct tpilha pilha;
int op;

// prototipa��o:
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

int main(int argc, char** argv) {
	// a��es principais:
	setlocale(LC_ALL, "Portuguese");
	op = 1;
	pilha.ini = 0;
	pilha.fim = 0;
	while (op != 0) {
		system("cls");
		pilha_mostrar();
		menu_mostrar();
		scanf("%d", &op);
		switch(op) {
			case 1:
				pilha_entrar();
			break;
			case 2:
				pilha_sair();
			break;
		}
	}
	
	return 0;
}

// fun��o adicionar um elemento no final da Pilha:
	void pilha_entrar() {
		if (pilha.fim == tamanho) {
			printf("\nA pilha est� cheia, imposs�vel empilhar!\n\n");
			system("pause");
		} else {
			printf("\nDigite o valor a ser empilhado: ");
			scanf("%d", &pilha.dados[pilha.fim]);
			pilha.fim++;
		}
	}
	
	// fun��o retirar o �ltimo elemento da Pilha:
	void pilha_sair() {
		if (pilha.ini == pilha.fim) {
			printf("\nA pilha est� vazia, imposs�vel desempilhar!\n\n");
			system("pause");
		} else {
			pilha.dados[pilha.fim-1] = 0;
			pilha.fim--;
		}
	}
	
	// fun��o mostrar o conte�do da Pilha:
	void pilha_mostrar() {
		int i;
		printf("[ ");
		for (i=0; i<tamanho; i++) {
			printf("%d ", pilha.dados[i]);
		}
		printf("]\n\n");
	}
	
	// fun��o mostrar o menu de op��es:
	void menu_mostrar() {
		printf("\nEscolha uma op��o:\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("0 - Sair\n\n");
	}
