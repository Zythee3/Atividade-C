#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Fila
{
    struct Elemento *inicio;
    struct Elemento *fim;
} Fila;

Fila *cria_fila()
{
    Fila *fila = malloc(sizeof(Fila));
    fila->fim = NULL;
    fila->inicio = NULL;

    return fila;
}

void insere_fila(Fila *fila, int num)
{
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = num;

    if (novo == NULL) // Verifica se a alocação de memória falhou
    {
        printf("Erro na alocação de memória\n");
        return;
    }
    if (fila->inicio == NULL)
    {
        fila->inicio = novo;
        fila->fim = novo;
    }
    else
    {
        fila->fim->proximo = novo;
        fila->fim = novo;
    }
}

int contador(Fila *fila)
{
    int contador = 0;
    Elemento *leitor;
    leitor = fila->inicio;

    while (leitor != NULL)
    {
        contador = contador + 1;
        leitor = leitor->proximo;
        printf("AAAAAA");
    }
    printf("%d", contador);
    return contador;
}

int main()
{
    srand(time(NULL));
    Fila *fila_P1 = cria_fila();
    Fila *fila_P2 = cria_fila();

    int tamanho_P1, tamanho_P2;
    int opcao_escolha;
    int quantidade_P1 = rand() % 10;
    int quantidade_P2 = rand() % 10;

    for (int i = 0; i < quantidade_P1; i++)
    {
        int num_P1 = rand() % 10;
        insere_fila(fila_P1, num_P1);
    }
    for (int j = 0; j < quantidade_P2; j++)
    {
        int num_P2 = rand() % 10;
        insere_fila(fila_P2, num_P2);
    }
    printf("\n1 - Comparar as filas\n2 - Exibir maior/menor/media\n3 - Transferir elementos\n4 - Exibir numeros impares\n5 - Exibir numeros pares\n");
    scanf("%d", &opcao_escolha);

    switch (opcao_escolha)
    {
    case 1:
        printf("Sim");
        tamanho_P1 = contador(fila_P1);
        // -

        if (tamanho_P1 > tamanho_P2)
        {
            printf("\nA fila P1 eh maior que a fila P2 por %d elementos\n", tamanho_P1 - tamanho_P2);
        }
        else if (tamanho_P2 > tamanho_P1)
        {
            printf("A fila P1 eh maior que a fila P2 por %d elementos\n", tamanho_P2 - tamanho_P1);
        }
        break;

    default:
        break;
    }
}