#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo a estrutura da lista:
struct no {
	int dado;
	struct no *proximo;
};

//definindo variáveis:
typedef struct no *ptr_no;
ptr_no lista;
int op;

// prototipação:
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

int main(int argc, char *argv[]) {
	
	//inicializando máquina de números randômicos
	srand(time(NULL));
	op = 1;
	//criando o primeiro nó da lista:
	lista = (ptr_no) malloc(sizeof(struct no));
	lista->dado = 0;
	lista->proximo = NULL;
	//laço principal:
	while(op != 0) {
		system("cls");
		menu_mostrar();
		scanf("%d", &op);
		menu_selecionar(op);
	}
	system("Pause");
	return 0;
}

// mostra o menu de opções:
void menu_mostrar() {
	lista_mostrar(lista);
	printf("\n\nEscolha uma das opcoes:\n");
	printf("1 - Inserir no final da Lista\n");
	printf("2 - Remover um item da Lista\n");
	printf("0 - Sair\n\n");
}
// executa a opção escolhida no menu
void menu_selecionar(int op) {
	switch(op){
		case 1:
			lista_inserir(lista);
		break;
		case 2:
			lista_remover(lista);
		break;
	}
}
// insere um elemento no final da lista:
void lista_inserir(ptr_no lista) {
	while(lista->proximo != NULL) {
		lista = lista->proximo;
	}
	lista->proximo = (ptr_no) malloc(sizeof(struct no));
	lista = lista->proximo;
	lista->dado = rand()%100;
	lista->proximo = NULL;
}
// remove um elemento da lista:
void lista_remover(ptr_no lista) {
	int dado;
	ptr_no atual;
	atual = (ptr_no) malloc(sizeof(struct no));
	printf("\n\nEscolha um dos itens:\n");
	scanf("%d", &dado);
	while(lista->dado != dado) {
		if (lista->proximo == NULL) {
			break;
		}
		atual = lista;
		lista = lista->proximo;
	}
	if(lista->dado == dado) {
		atual->proximo = lista->proximo;
	}
}

// desenha o conteudo da lista na tela
void lista_mostrar(ptr_no lista) {
	system("cls");
	while(1) {
		printf("%d, ", lista->dado);
		if(lista->proximo == NULL) {
			break;
		}
		lista = lista->proximo;
	}
}

// desenha o conteúdo da lista na tela

