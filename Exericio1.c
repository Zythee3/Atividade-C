#include <stdio.h>
#include <stdlib.h>

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
}

void insere_pilha(Pilha *pilha)
{
    No *novo = malloc(sizeof(No));
    printf("Escolha o valor a ser adicionado:");
    scanf("%d", &novo->valor);

    novo->proximo = pilha->topo;
    pilha->topo = novo;
    printf("\nNumero inserido na pilha!!\n");
    getch();
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

int main()
{
    Pilha *P1 = cria_pilha();
    Pilha *P2 = cria_pilha();
    
    int opcao, tamanho_P1, tamanho_P2;
    
    while(opcao != 3){ 
        opcao = 0;
        printf("1 - Inserir numero na pilha\n");
        printf("2 - Comprar o tamanho das pilhas\n");
        fflush(stdout);
        int opcao_case_1;
        scanf("%d", &opcao);
        switch (opcao)
        {
        
        case 1:
            do
            {
                opcao_case_1 = 0;
                printf("1 - P1\n");
                printf("2 - P2\n");
                printf("Escolha qual Pilha deseja inserir um numero:");
                fflush(stdout);
                scanf("%d", &opcao_case_1);
                printf("\n-------------------------------------------------\n");
            } while (opcao_case_1 != 1 && opcao_case_1 != 2);
            if (opcao_case_1 == 1)
            {
                insere_pilha(P1);
            }
            else{
                insere_pilha(P2);
            }
            break;
        
        case 2:
            tamanho_P1 = contador(P1);
            tamanho_P2 = contador(P2);
            if( tamanho_P1 > tamanho_P2){
                printf("A pilha P1 e maior que a P2 por %d elementos\n", tamanho_P1 - tamanho_P2);
                fflush(stdout);

            }
            else if(tamanho_P1 == tamanho_P2){
                printf("As duas pilhas sao do mesmo tamanho\n");
                fflush(stdout);
            }
            else{
                printf("A pilha P2 e maior que a P1 por %d elementos\n", tamanho_P2 - tamanho_P1);
                fflush(stdout);
            }
            break;

        default:
            break;
        }
    }
}
