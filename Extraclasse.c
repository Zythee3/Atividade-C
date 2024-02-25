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
    
    }

void insere_fila(Fila *fila, int idade, int prioridade) {
    
    Elemento *novo = malloc(sizeof(Elemento));
    Elemento *aux, *ant = fila->inicio;

    novo->prioridade = prioridade;
    novo->idade = idade;
    novo->prox = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novo;
        fila->fim = novo;
        printf("\nPessoa com idade %d de prioridade: %d inserida na fila!\n", novo->idade, novo->prioridade);
    }   
    
    //verifica caso a prioridade do novo numero já seja maior do que o inicio da fila
    else if(fila->inicio->prioridade < novo->prioridade){
        novo->prox = fila->inicio;
        fila->inicio = novo;
        printf("\nPessoa com idade %d de prioridade: %d inserida na fila!\n", novo->idade, novo->prioridade);
    }

    else {
        while(aux != NULL){
            if(aux->prioridade < novo->prioridade){
                novo->prox = aux;
                ant->prox = novo;
                break;
            }
            // caso a prioridade da nova idade seja menor que todas as outras idades ela ira ser adicionada no fim da fila
            if(aux->prox == NULL && aux->prioridade > novo->prioridade){
                aux->prox = novo;
                fila->fim = novo;
                break;
            }
            if(aux->idade != ant->idade){
                ant = ant->prox;
            }
            aux = aux->prox;
            
        }
        printf("\nPessoa com idade %d de prioridade: %d inserida na fila!\n", novo->idade, novo->prioridade);
    }
    
}

void altera_prioridade(Fila *fila){
    Elemento *aux = fila->inicio;
    int nova_prioridade;

    while(aux != NULL){
        
        printf("Insira a nova prioridade da idade %d", aux->idade);
        scanf("%d", &nova_prioridade);
        printf("prioridade alterada");
        insere_fila(fila, aux->idade, nova_prioridade);
        free(aux);
        aux= aux->prox;

    }
}



int main(){
    Fila *fila_primaria = CriarFila();
    Fila *fila_auxiliar = CriarFila();

    int menu, idade, prioridade;
    while(menu != 4){
        
        printf("\n1 - Insere idade\n2 - Exibir quantidade de numeros na fila\n3 - Comparar prioridades\n4 - Sair\n");
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
            Imprimir(fila_primaria);
            break;
        default:
            break;
        }
    }
}
