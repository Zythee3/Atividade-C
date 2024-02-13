#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no
{
    int valor;
    struct no *proximo;
} No;

typedef struct pilha
{
    No *topo;
} Pilha;

Pilha *cria_pilha()
{
    Pilha *pi = malloc(sizeof(pi));

    if (pi)
    {
        pi->topo = NULL;
    }
    else
    {
        printf("Falha ao criar a Pilha...");
    }
    return pi;
}

void insere_pilha(Pilha *pilha, int num)
{
    No *novo = malloc(sizeof(No));
    novo->valor = num;

    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int contador(Pilha *pilha)
{
    int contador = 0;
    No *aux;
    if (pilha->topo == NULL)
    {
        return contador;
    }

    else
    {
        aux = pilha->topo;
        while (aux != NULL)
        {
            contador = contador + 1;
            aux = aux->proximo;
        }
    }
    return contador;
}
void imprimi_pilha(Pilha *pilha)
{
    No *aux;

    aux = pilha->topo;
    while (aux != NULL)
    {
        printf("%d\n", aux->valor);
        aux = aux->proximo;
    }
}

void copia_elementos(Pilha *pilha_copiada, Pilha *pilha)
{
    No *leitor = pilha_copiada->topo;

    while(leitor != NULL){
        insere_pilha(pilha, leitor->valor);
        leitor = leitor->proximo;
    }

}

void analisa_pilha(Pilha *pilha, int tamanho)
{
    No *leitor;
    int menor, maior;
    float media;

    leitor = pilha->topo;

    menor = leitor->valor;
    maior = leitor->valor;
    while (leitor != NULL)
    {
        if (leitor->valor < menor)
        {
            menor = leitor->valor;
        }
        if (leitor->valor > maior)
        {
            maior = leitor->valor;
        }
        media = media + leitor->valor;
        leitor = leitor->proximo;
    }

    printf("O menor numero da pilha eh: %d\n", menor);
    printf("O maior numero da pilha eh: %d\n", maior);
    printf("A media foi %.2f\n", media / tamanho);
}

void pilha_par(Pilha *pilha){
    No *leitor = pilha->topo;
    int contador = 0;
    while(leitor != NULL){
        if(leitor->valor % 2 == 0){
            contador++;
        }
        leitor = leitor->proximo;
    }
    printf("%d", contador);
}
void pilha_impar(Pilha *pilha){
    No *leitor = pilha->topo;
    int contador = 0;

    while(leitor !=NULL){
        if(leitor->valor % 2 != 0){
            contador ++;
            
        }
        leitor = leitor->proximo;
    }
    printf("%d", contador);
}

int main()
{
    srand(time(NULL));
    Pilha *P1 = cria_pilha();
    Pilha *P2 = cria_pilha();

    // adiciona os numeros aleatorios nas pilhas

    int quantidade_P1 = rand() % 10;
    int quantidade_P2 = rand() % 10;

    for (int i = 0; i < quantidade_P1; i++)
    {
        int num = rand() % 10;
        insere_pilha(P1, num);
    }

    for (int j = 0; j < quantidade_P2; j++)
    {
        int num2 = rand() % 10;
        insere_pilha(P2, num2);
    }

    int opcao, tamanho_P1, tamanho_P2, opcao_case_3;

    while (opcao != 6)
    {
        printf("----------- Pilha 1 -----------\n");
        imprimi_pilha(P1);
        printf("----------- Pilha 2 -----------\n");
        imprimi_pilha(P2);

        opcao = 0;
        printf("\n1 - Comparar as pilhas\n");
        printf("2 - Exibir media/menor/maior pilha\n");
        printf("3 - Transferir elementos\n");
        printf("4 - Ver numeros impares\n");
        printf("5 - Ver numeros pares\n");
        printf("6 - sair\n");
        fflush(stdout);

        scanf("%d", &opcao);
        switch (opcao)
        {

        case 1:
            tamanho_P1 = contador(P1);
            tamanho_P2 = contador(P2);
            if (tamanho_P1 > tamanho_P2)
            {
                printf("A pilha P1 eh maior que a P2 por %d elementos\n", tamanho_P1 - tamanho_P2);
                fflush(stdout);
            }
            else if (tamanho_P1 == tamanho_P2)
            {
                printf("As duas pilhas sao do mesmo tamanho\n");
                fflush(stdout);
            }
            else
            {
                printf("A pilha P2 eh maior que a P1 por %d elementos\n", tamanho_P2 - tamanho_P1);
                fflush(stdout);
            }
            break;

        case 2:
            analisa_pilha(P1, contador(P1));
            printf("\n");
            analisa_pilha(P2, contador(P2));
            break;
        case 3:
            opcao_case_3 = 0;
            printf("1 - Copiar P1 para P2\n2 - Copiar P2 para P1\n");
            scanf("%d", &opcao_case_3);
            if(opcao_case_3 == 1){
                copia_elementos(P1, P2);
            }
            else if(opcao_case_3 == 2){
                copia_elementos(P2, P1);
            }
            break;
        case 4:
            printf("A quantidade de numeros impares da P1: ");
            pilha_impar(P1);
            printf("\n-------------------------------------\n");
            printf("A quantidade de numero impares da P2: ");
            pilha_impar(P2);
            printf("\n-------------------------------------\n");
            break;
        case 5:
            printf("A quantidade de numeros pares da P1: ");
            pilha_par(P1);
            printf("\n-------------------------------------\n");
            printf("A quantidade de numero pares da P2: ");
            pilha_par(P2);
            printf("\n-------------------------------------\n");
        default:

            break;
        }
    }
}
