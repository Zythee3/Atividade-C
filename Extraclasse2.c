#include <stdio.h>

void insere_array_comum(int array[], int *tamanho, int elemento) {
    array[*tamanho] = elemento;
    (*tamanho)++;
}

void insere_array_prioridade(int array[], int *tamanho, int elemento) {
    int i, j;

    for (i = 0; i < *tamanho; i++) {
        if (array[i] > elemento) {
            break;
        }
    }

    for (j = *tamanho; j > i; j--) {
        array[j] = array[j - 1];
    }

    array[i] = elemento;
    (*tamanho)++;
}

int main() {
    int array_comum[10];
    int array_prioridade[10];
    int tamanho_comum = 0;
    int tamanho_prioridade = 0;
    int i, num, menu = 0;

    while(menu != 4)
    {    printf("\n1 - Insere numero comum\n2 - Insere numero prioridade\n3 - imprimir fila\n4 - Sair\n\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            for (i = 0; i < 3; i++) {
                printf("Insira um numero para o array comum: ");
                scanf("%d", &num);
                insere_array_comum(array_comum, &tamanho_comum, num);
            }
            break;
        case 2:
            for (i = 0; i < 3; i++) {
                printf("Insira um numero para o array de prioridade: ");
                scanf("%d", &num);
                insere_array_prioridade(array_prioridade, &tamanho_prioridade, num);
            }
            break;
        case 3:
            for (i = 0; i < tamanho_prioridade; i++) {
                printf(" %d ", array_prioridade[i]);
            }

            for (i = 0; i < tamanho_comum; i++) {
                printf(" %d ", array_comum[i]);
            }
            break;
        default:
            break;
        }
        
        }
}