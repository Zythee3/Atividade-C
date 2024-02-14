#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Pilha
{
    Elemento *topo;
} Pilha;

typedef struct Fila
{
    Elemento *inicio;
    Elemento *fim;
} Fila;

Pilha *cria_pilha()
{
    Pilha *novo = malloc(sizeof(Pilha));
    novo->topo = NULL;
    return novo;
}

Fila *cria_fila()
{
    Fila *novo = malloc(sizeof(Fila));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void insere_pilha(Pilha *pilha, int numero)
{
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = numero;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void insere_Fila(Fila *fila, int numero)
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
void imprimi_Pilha(Pilha *pilha)
{
    Elemento *leitor = pilha->topo;
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
    do
    {
        printf(" %d ", leitor->valor);
        leitor = leitor->proximo;
    } while (leitor != NULL);
}
void analisa_lista_pilha(Pilha *pilha, Fila *fila)
{
    Elemento *leitor_pilha = malloc(sizeof(Elemento));
    Elemento *leitor_fila = malloc(sizeof(Elemento));

    leitor_fila = fila->inicio;
    leitor_pilha = pilha->topo;

    
    while(leitor_pilha != NULL){
        while(leitor_fila != NULL){
            
            if(leitor_pilha->valor == leitor_fila->valor){
                printf(" %d ", leitor_pilha->valor);
                
            }
            leitor_fila = leitor_fila->proximo;
        }
        leitor_fila = fila->inicio;
        leitor_pilha = leitor_pilha->proximo;
    }
}

int main()
{
    srand(time(NULL));
    Fila *fila = cria_fila();
    Pilha *pilha = cria_pilha();

    for (int i = 0; i <= 5; i++)
    {
        int num_fila = rand() % 10;
        insere_Fila(fila, num_fila);
        int num_pilha = rand() % 10;
        insere_pilha(pilha, num_pilha);
    }
    printf("\nPilha:\n");
    imprimi_Pilha(pilha);
    printf("\nFila\n");
    imprimi_fila(fila);
    printf("\nOs numeros que apareceram em ambas as estruturas foram: \n");
    analisa_lista_pilha(pilha, fila);
}