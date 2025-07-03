#include <stdio.h>  // Para printf
#include <stdlib.h> // Para malloc, calloc, realloc, free

int main() {
    // --- 1. Usando malloc() ---
    // malloc aloca um bloco de memória para um número especificado de bytes.
    // Ele não inicializa a memória, então ela pode conter "lixo".
    printf("--- Testando malloc() ---\n");
    int *ptr_malloc;
    int n_malloc = 5;
    int i;

    // Aloca memória para 5 inteiros (5 * sizeof(int) bytes)
    ptr_malloc = (int *) malloc(n_malloc * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (ptr_malloc == NULL) {
        printf("Falha na alocacao de memoria com malloc!\n");
        return 1; // Retorna com erro
    }

    printf("Memoria alocada com malloc para %d inteiros.\n", n_malloc);
    // Inicializa e imprime os valores
    
    for (i = 0; i < n_malloc; i++) {
        ptr_malloc[i] = i + 1;
        printf("%d ", ptr_malloc[i]);
    }
    printf("\n");

    // --- 2. Usando calloc() ---
    // calloc aloca um bloco de memória para um número especificado de elementos
    // de um certo tamanho e inicializa todos os bits da memória com zero.
    printf("\n--- Testando calloc() ---\n");
    int *ptr_calloc;
    int n_calloc = 3;

    // Aloca memória para 3 inteiros e inicializa com zero
    ptr_calloc = (int *) calloc(n_calloc, sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (ptr_calloc == NULL) {
        printf("Falha na alocacao de memoria com calloc!\n");
        return 1;
    }

    printf("Memoria alocada com calloc para %d inteiros (inicializados com zero):\n", n_calloc);
    // Imprime os valores (devem ser zero)
    for (i = 0; i < n_calloc; i++) {
        printf("%d ", ptr_calloc[i]);
    }
    printf("\n");

    // --- 3. Usando realloc() ---
    // realloc redimensiona um bloco de memória previamente alocado.
    // Pode aumentar ou diminuir o tamanho.
    printf("\n--- Testando realloc() ---\n");
    int *ptr_realloc;
    int n_original = 2;
    int n_novo = 4;

    // Aloca memória inicial para 2 inteiros
    ptr_realloc = (int *) malloc(n_original * sizeof(int));
    if (ptr_realloc == NULL) {
        printf("Falha na alocacao inicial com malloc para realloc!\n");
        return 1;
    }
    ptr_realloc[0] = 10;
    ptr_realloc[1] = 20;
    printf("Array original com realloc (2 elementos): %d %d\n", ptr_realloc[0], ptr_realloc[1]);

    // Redimensiona para 4 inteiros
    ptr_realloc = (int *) realloc(ptr_realloc, n_novo * sizeof(int));
    if (ptr_realloc == NULL) {
        printf("Falha na realocacao de memoria com realloc!\n");
        return 1;
    }

    printf("Memoria realocada para %d inteiros.\n", n_novo);
    // Preenche os novos elementos e imprime tudo
    ptr_realloc[2] = 30;
    ptr_realloc[3] = 40;
    printf("Array apos realloc (4 elementos): ");
    for (i = 0; i < n_novo; i++) {
        printf("%d ", ptr_realloc[i]);
    }
    printf("\n");

    // --- 4. Usando free() ---
    // free libera a memória previamente alocada dinamicamente.
    // É crucial para evitar vazamentos de memória.
    printf("\n--- Testando free() ---\n");

    // Libera a memória alocada por malloc
    free(ptr_malloc);
    printf("Memoria alocada por malloc liberada.\n");
    ptr_malloc = NULL; // Boa prática: definir o ponteiro como NULL após liberar

    // Libera a memória alocada por calloc
    free(ptr_calloc);
    printf("Memoria alocada por calloc liberada.\n");
    ptr_calloc = NULL;

    // Libera a memória alocada por realloc
    free(ptr_realloc);
    printf("Memoria alocada por realloc liberada.\n");
    ptr_realloc = NULL;

    printf("\nTodos os blocos de memoria dinamica foram liberados.\n");

    return 0; // Saída bem-sucedida do programa
}
