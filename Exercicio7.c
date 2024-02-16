#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Pilha
{
    struct Elemento *topo;
} Pilha;

typedef struct Fila
{
    struct Elemento *inicio;
    struct Elemento *fim;
} Fila;

Fila *cria_fila()
{
    Fila *novo = malloc(sizeof(Fila));
    novo->fim = NULL;
    novo->inicio = NULL;
    return novo;
}
Pilha *cria_pilha()
{
    Pilha *novo = malloc(sizeof(Pilha));
    novo->topo = NULL;
    return novo;
}

void insere_Pilha(Pilha *pilha, int numero)
{
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = numero;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void insere_fila(Fila *fila, int numero)
{
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = numero;
    novo->proximo = NULL;

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

void imprimi_pilha(Pilha *pilha)
{
    Elemento *leitor;
    leitor = pilha->topo;
    while (leitor != NULL)
    {
        printf(" %d ", leitor->valor);
        leitor = leitor->proximo;
    }
}

void imprimi_fila(Fila *fila)
{
    Elemento *leitor;
    leitor = fila->inicio;
    if (leitor != NULL)
    {
        while (leitor != NULL)
        {

            printf(" %d ", leitor->valor);
            leitor = leitor->proximo;
        }
    }
    else
    {
        printf("A lista esta vazia");
    }
}

int main()
{
    Pilha *pilha = cria_pilha();
    Fila *fila_impar = cria_fila();
    Fila *fila_par = cria_fila();

    int numero;
    while (numero >= 0)
    {
        numero = 0;
        printf("Digite um numero qualquer(caso queira para o programa insira um numero negativo qualquer):\n");
        scanf("%d", &numero);
        if(numero < 0){
            break;
        }
        insere_Pilha(pilha, numero);

        if (numero % 2 == 0)
        {
            insere_fila(fila_par, numero);
        }
        else
        {
            insere_fila(fila_impar, numero);
        }
    }
    printf("\nFila dos numeros pares:\n");
    imprimi_fila(fila_par);
    printf("\nFila dos numeros impares\n");
    imprimi_fila(fila_impar);
    printf("\nPilha de todos os numeros digitados:\n");
    imprimi_pilha(pilha);
}