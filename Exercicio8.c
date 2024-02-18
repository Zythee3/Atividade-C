#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Elemento
{
    int id;
    char tipo[1];
    float preco;
    struct Elemento *proximo;
} Elemento;

typedef struct Tipo
{
    int imposto;
    char nome[1];
    Fila *elementos;
    struct Tipo *proximo;
} Tipo;
typedef struct Fila
{
    struct Elemento *inicio;
    struct Elemento *fim;
    struct Tipo *inicio_t;
    struct Tipo *fim_t;
} Fila;

void insere_fila_tipo(Fila *fila, char nome[1], int imposto)
{
    Tipo *novo = malloc(sizeof(Tipo));

    strcpy(novo->nome, nome);
    novo->imposto = imposto;
    if (fila->inicio == NULL)
    {
        fila->inicio_t = novo;
        fila->fim_t = novo;
    }
    else
    {
        fila->fim_t->proximo = novo;
        fila->fim_t = novo;
    }
}


int verifica_imposto(Fila *fila, char tipo[1]){
    
    Tipo *leitor;
    leitor = fila->inicio_t;
    while(leitor != NULL){
        if(strcmp(leitor->nome, tipo) == 0){
            return leitor->imposto;
        }
        leitor->proximo;
    }
}

void imprimi_fila_elemento_verifica(Fila *fila, Fila *fila_t)
{   
    int escolha_id;
    
    Elemento *leitor;
    int imposto;
    char tipo_id[1];
    
    leitor = fila->inicio;
    while(leitor != NULL){
        printf("ID:%d\n", leitor->id);
        leitor = leitor->proximo;
    }
    printf("Escolha qual produto deseja ver o preco:\n");
    scanf("%d", &escolha_id);
    
    leitor = fila->inicio;
    
    while(leitor != NULL){
        if(leitor->id == escolha_id){
            printf("\nProduto encontrado\n");
            printf("%d", leitor->preco);
            // tipo_id[1] = leitor->tipo;
            // imposto = verifica_imposto(fila_t, tipo_id[1]);    
            // printf("preco = %d", leitor->preco * (imposto/100));
            break;
        }
        leitor = leitor->proximo;
    }
    

}

void remove_tipo_se_vazio(Tipo **inicio, char *nome) {
    Tipo *anterior = NULL;
    Tipo *atual = *inicio;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            
            if (atual->elementos->inicio == NULL) {
                
                if (anterior == NULL) {
                    *inicio = atual->proximo;
                } else {
                    anterior->proximo = atual->proximo;
                }
                free(atual);
                return;
            } else {
                printf("O tipo %s não está vazio.\n", nome);
                return;
            }
        }
        anterior = atual;
        atual = atual->proximo;
    }

    printf("O tipo %s não foi encontrado.\n", nome);
}




void insere_fila_elementos(Fila *fila,Fila *fila_tipo, char tipo[1], int id, float preco)
{
    Elemento *novo = malloc(sizeof(Elemento));
    Tipo *leitor;
    leitor = fila_tipo->inicio_t;
    strcpy(novo->tipo, tipo);
    int temnafila = 0;
    printf("%s\n", novo->tipo);
    printf("%s", leitor->nome);
    while(leitor != NULL){
        if(strcmp(leitor->nome, tipo) == 0){
            temnafila = temnafila +1;
            break;
        }
        leitor = leitor->proximo;
    }



    if (temnafila == 1)
    {

        novo->id = id;
        novo->preco = preco;

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
    else
    {
        printf("\nTipo nao existe\n");
    }
}

int contador_tipo(Fila *fila)
{
    int contador = 0;
    Tipo *leitor;
    leitor = fila->inicio;
    while (leitor != NULL)
    {
        contador = contador + 1;
        leitor = leitor->proximo;
    }
    contador = contador + 1;

    return contador;
}

void imprimi_fila(Fila *fila)
{
    Tipo *leitor;
    leitor = fila->inicio_t;

    while (leitor != NULL)
    {
        printf("Tipo: %s\nImposto:%d\n", leitor->nome, leitor->imposto);
        leitor = leitor->proximo;
    }
}

Fila *cria_fila()
{
    Fila *fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}
Fila *cria_fila_tipo()
{
    Fila *fila = malloc(sizeof(Fila));
    fila->inicio_t = NULL;
    fila->fim = NULL;
    return fila;
}

int main()
{
    Fila *fila_tipos = cria_fila_tipo();
    Fila *fila_elementos = cria_fila();

    int opcao, imposto;
    float preco;
    char nome[1], tipo[1];
    while (opcao != 5)
    {
        printf("\n-- Menu --\n1 - Cadastrar tipo\n2 - Cadastrar produto\n3 - Consultar preco de um produto\n4 - Excluir tipo\n5 - Sair\n");
        printf("Escolha sua opcao: \n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInforme a letra do tipo:\n");
            scanf("%s", &tipo);
            printf("\nInforme o valor do imposto: ");
            scanf("%d", &imposto);

            insere_fila_tipo(fila_tipos, tipo, imposto);
            break;
        case 2:
            // imprimi_fila(fila_tipos);
            printf("\nInforme o tipo do produto:\n");
            scanf("%s", &nome);
            printf("Informe o preco do produto:\n");
            scanf("%f", &preco);
            insere_fila_elementos(fila_elementos,fila_tipos, nome, contador_tipo(fila_elementos), preco);
            
            break;
            
        case 3:
            imprimi_fila_elemento_verifica(fila_elementos, fila_tipos);
        case 4:
            char nome[50]; // Ajuste o tamanho do array conforme necessário
            printf("Digite o nome do tipo que você deseja remover: ");
            scanf("%s", nome);
            remove_tipo_se_vazio(&inicio, nome);
            break;
        
        default:
        
        
            break;
        }
    }
}