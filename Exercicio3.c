#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct elemento{
    int valor;
    struct Elemento *proximo;
}Elemento;

typedef struct pilha{
    Elemento *topo;
}Pilha;

Pilha *cria_pilha(){
    Pilha *pilha = malloc(sizeof(Pilha));
    if(pilha)
    {
        pilha->topo = NULL;
    }
    else
    {
        printf("Falha ao criar a Pilha...");
    }
    return pilha;
}

void insere_pilha(Pilha *pilha, int num){
    Elemento *novo = malloc(sizeof(Elemento));
    novo->valor = num;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void fibonacci(Pilha *pilha, int quantidade){
    int t1 = 0, t2 = 1, proximo;

    insere_pilha(pilha, t1);
    insere_pilha(pilha, t2);
    for(int i= 1; i <=quantidade; i++){
        proximo = t1 + t2;
        insere_pilha(pilha, proximo);
        t1 = t2;
        t2 = proximo;
    }
}

void imprimi_Pilha(Pilha *pilha){
    Elemento *aux = pilha->topo;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}

int main(){
    srand(time(NULL));
    Pilha * pilha = cria_pilha();
    int quantidade = rand() % 10;
    fibonacci(pilha, quantidade);
    imprimi_Pilha(pilha);

}