#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *proximo;
} Elemento;

typedef struct Pilha
{
    Elemento *topo;
} Pilha;

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
    printf("\nNumero inserido com sucesso!!\n");
}
void imprimi_numeros_pares(Pilha *pilha)
{
    Elemento *leitor = pilha->topo;
    while (leitor != NULL)
    {
        if (leitor->valor % 2 == 0)
        {
            printf(" %d ", leitor->valor);
        }
        leitor = leitor->proximo;
    }
}

void remove_elemento(Pilha *pilha)
{
    Elemento *leitor = pilha->topo;
    if (pilha->topo == NULL)
    {
        printf("\nA pilha esta vazia\n");
    }
    else
    {
        printf("\n %d removido!!\n", pilha->topo->valor);
        pilha->topo = pilha->topo->proximo;
        free(leitor);
        
    }
}

int main()
{
    Pilha *pilha = cria_pilha();
    int opcao_menu, num_case1;
    int ch;
    
    while(opcao_menu != 4){
        opcao_menu = 0;
        printf("\n1 - Cadastrar numero\n2 - Mostrar numeros pares\n3 - Excluir numero\n4 - Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao_menu);
        if (opcao_menu != 1) {
            opcao_menu = -1;
        }
        while ((ch = getchar()) != '\n' && ch != EOF); // Limpa o buffer
        switch (opcao_menu)
        {
        case 1:
            num_case1 = 0;
            printf("Escolha um numero: ");
            scanf("%d", &num_case1);
            insere_Pilha(pilha, num_case1);
            break;
        case 2:
            imprimi_numeros_pares(pilha);
            break;
        case 3:
            remove_elemento(pilha);
            break;
        case 4:
            printf("Programa encerrado");
            opcao_menu = 4;
            break;
        default:
            printf("opcao invalida");
            
            break;
        }
    }
}