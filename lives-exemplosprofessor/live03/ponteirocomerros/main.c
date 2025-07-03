#include <stdio.h>
#include <stdlib.h>

void acesso_memoria() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int i;
    printf("Elementos do array: {");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {  // Corrigido: faltava um par�ntese
        printf("%d", *(ptr + i));
        if (i < (sizeof(arr) / sizeof(arr[0]) - 1)) {  // Adicionado para separar os elementos com v�rgula
            printf(", ");
        }
    }
    printf("}\n");
    
    // Acesso fora dos limites foi mantido, mas � um comportamento perigoso
    printf("Valor fora dos limites do array: %d\n", *(ptr + 15));  // Isso � um acesso inv�lido!
    getchar();
}

int main(int argc, char *argv[]) {
    acesso_memoria();
    return 0;
}
