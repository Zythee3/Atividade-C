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
    novo->proximo = NULL;

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

void consulta_fila(Fila *fi){
	
    Elemento *aux;
	
	aux = fi->inicio;
	do{
		printf(" %d ", aux->valor);
		aux = aux->proximo;
	} while(aux != NULL);
}
void copia_elementos(Fila *fila_copiada, Fila *fila_destino){
    Elemento *leitor;
    leitor = fila_copiada->inicio;

    while(leitor != NULL){
        insere_fila(fila_destino, leitor->valor);
        leitor = leitor->proximo;
    }
}


int contador(Fila *fila)
{
    int contador = 0;
    Elemento *leitor;
    leitor = fila->inicio;

    while(leitor != NULL){
        contador = contador + 1;
        leitor = leitor->proximo;
    }
    
    return contador;
}
void analisa_fila(Fila *fila, int contador){
    int maior, menor;
    float media = 0;
    Elemento *leitor;

    leitor = fila->inicio;

    maior = leitor->valor;
    menor = leitor->valor;

    while(leitor != NULL){
        if(leitor->valor > maior){
            maior = leitor->valor;
        }
        else if(leitor->valor < menor){
            menor = leitor->valor;
        }
        media = media + leitor->valor;
        leitor = leitor->proximo;

    }
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media: %.2f\n", media/contador);
    
}

void analisa_impares(Fila *fila){
    Elemento *leitor;
    int contador = 0;
    leitor = fila->inicio;
    while(leitor != NULL){
        if(leitor->valor % 2 != 0){
            contador++;
        }
        leitor = leitor->proximo;
    }
    printf("Numeros impares: %d", contador);
}

void analisa_pares(Fila *fila){
    Elemento *leitor;
    int contador = 0;
    leitor = fila->inicio;
    while(leitor != NULL){
        if(leitor->valor % 2 == 0){
            contador++;
        }
        leitor = leitor->proximo;
    }
    printf("Numeros pares: %d", contador);
}

int main()
{
    srand(time(NULL));
    Fila *fila_P1 = cria_fila();
    Fila *fila_P2 = cria_fila();

    int tamanho_P1, tamanho_P2;
    int opcao_escolha, escolha_case_3;
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
    
    while(opcao_escolha != 6){
        opcao_escolha = 0;
        printf("\nFila P1\n");
        consulta_fila(fila_P1);
        printf("\nFila P2\n");
        consulta_fila(fila_P2);
        fflush(stdout);
        printf("\n\n1 - Comparar as filas\n2 - Exibir maior/menor/media\n3 - Transferir elementos\n4 - Exibir numeros impares\n5 - Exibir numeros pares\n6 - Sair\n");
        scanf("%d", &opcao_escolha);

        switch (opcao_escolha)
        {
        case 1:
            tamanho_P1 = contador(fila_P1);
            tamanho_P2 = contador(fila_P2);

            if (tamanho_P1 > tamanho_P2)
            {
                printf("\nA fila P1 eh maior que a fila P2 por %d elementos\n", tamanho_P1 - tamanho_P2);
            }
            else if (tamanho_P2 > tamanho_P1)
            {
                printf("A fila P1 eh maior que a fila P2 por %d elementos\n", tamanho_P2 - tamanho_P1);
            }
            else if(tamanho_P1 == tamanho_P2){
                printf("As duas filas são iguais em tamanhos");
            }
            break;
        case 2:
            printf("Lista P1:\n");
            analisa_fila(fila_P1,contador(fila_P1));
            printf("\nLista P2:\n");
            analisa_fila(fila_P2,contador(fila_P2));
            break;
        case 3:
            escolha_case_3 = 0;
            printf("1 - Copiar da Fila P1 para P2\n2 - Copiar da Fila P2 para P1\nEscolha para qual fila deseja copiar: ");
            scanf("%d", &escolha_case_3);
            if(escolha_case_3 == 1){
                copia_elementos(fila_P1, fila_P2);
            }
            else if(escolha_case_3 == 2){
                copia_elementos(fila_P2, fila_P1);
            }
        case 4:
            printf("\nFila P1:\n");
            analisa_impares(fila_P1);
            printf("\nFila P2:\n");
            analisa_impares(fila_P2);
            break;
        case 5:
            printf("\nFila P1:\n");
            analisa_pares(fila_P1);
            printf("\nFila P2:\n");
            analisa_pares(fila_P2);
        
        default:
            break;
        }
    }
}