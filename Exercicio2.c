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
    if (fila->inicio = NULL)
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
void contador(Fila *fila)
{   
    int contador = 0;
    Elemento *leitor = fila->inicio;
    while(leitor!= NULL){
        contador++;
        leitor = leitor->proximo;
    }
    printf("%d", contador);
}

int main()
{
    srand(time(NULL));
    Fila *fila_P1 = cria_fila();
    Fila *fila_P2 = cria_fila();

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
    
}