#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
    int idade;
    int prioridade;
    struct Elemento *prox;
} Elemento;

typedef struct Fila {
    Elemento *inicio;
    Elemento *fim;
} Fila;

Elemento *aux; // Ponteiro Auxiliar

Fila *CriarFila() {
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
    }

void Imprimir(Fila *fila) {


    aux = fila->inicio;
    int contador = 0;
    
    while (aux != NULL) {
        contador ++;
        printf("--------- cliente %d ---------\nIdade: %d\nPrioridade: %d\n\n",contador, aux->idade, aux->prioridade);
        aux = aux->prox;
    }
    printf("A lista possui %d idades", contador);
    }

void insere_fila(Fila *fila, int idade, int prioridade) {
    Elemento *novo = malloc(sizeof(Elemento));
    Elemento *aux = fila->inicio;
    Elemento *ant = NULL;

    novo->prioridade = prioridade;
    novo->idade = idade;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
    } else if (fila->inicio->prioridade < novo->prioridade) {
        novo->prox = fila->inicio;
        fila->inicio = novo;
    } else {
        while (aux != NULL && aux->prioridade >= novo->prioridade) {
            ant = aux;
            aux = aux->prox;
        }
        novo->prox = aux;
        if (ant != NULL) {
            ant->prox = novo;
        }
        if (aux == NULL) {
            fila->fim = novo;
        }
    }
    printf("\nPessoa com idade %d de prioridade: %d inserida na fila!\n", novo->idade, novo->prioridade);
}
    
void compara_prioridades(Fila *fila, int prioridade){
    Elemento *aux = fila->inicio;
    int contador = 0;
    
    while(aux != NULL){
        if(aux->prioridade == prioridade)
            contador++;
        aux = aux->prox;
    }
    printf("Quantidade de idades nessa prioridade eh %d\n", contador);
}

void altera_prioridade(Fila *fila){
    Elemento *aux = fila->inicio;
    Fila *fila_auxiliar = CriarFila();
    int nova_prioridade;

    while(aux != NULL){
        printf("Insira a nova prioridade da idade %d: ", aux->idade);
        scanf("%d", &nova_prioridade);
        printf("prioridade alterada");
        fila->inicio = fila->inicio->prox;
        insere_fila(fila_auxiliar, aux->idade, nova_prioridade);
        free(aux);
        aux = fila->inicio;

    }
    aux = fila_auxiliar->inicio;
    while(aux != NULL){
        insere_fila(fila, aux->idade, aux->prioridade);
        aux = aux->prox;
    }
    
}


int main(){
    Fila *fila_primaria = CriarFila();
    int menu, idade, prioridade, case3;
    while(menu != 5){
        
        printf("\n1 - Insere idade\n2 - Altera a prioridade\n3 - Exibir quantidade de numeros na fila\n4 - Comparar prioridades\n5 - Sair\n");
        scanf("%d", &menu);
        switch (menu)
        {
        case 1:
            printf("\n o valor da idade: \n");
            scanf("%d", &idade);
            printf("\nInforme o valor da prioridade (1 - 10): \n");
            scanf("%d", &prioridade);
            insere_fila(fila_primaria, idade, prioridade);
            break;
        case 2:
            altera_prioridade(fila_primaria);
            break;
        case 3:
            Imprimir(fila_primaria);
            break;
        case 4:
            printf("Digite a prioridade que seja analisar: ");
            scanf("%d", &case3);
            compara_prioridades(fila_primaria, case3);
            break;
        default:
            break;
        }
    }
}
