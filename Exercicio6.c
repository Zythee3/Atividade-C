#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[50];
    int id;
    float nota1, nota2;
    struct Aluno *proximo;
} Aluno;

typedef struct Pilha
{
    Aluno *topo;
} Pilha;

typedef struct Fila
{
    Aluno *inicio;
    Aluno *fim;
} Fila;

Fila *cria_fila()
{
    Fila *novo = malloc(sizeof(Pilha));
    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

Pilha *cria_pilha()
{
    Pilha *novo = malloc(sizeof(Pilha));
    novo->topo = NULL;
    return novo;
}

void insere_fila(Fila *fila, float nota1, float nota2, int id)
{
    Aluno *novo = malloc(sizeof(Aluno));
    novo->nota1 = nota1;
    novo->nota2 = nota2;
    novo->id = id;
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

void insere_pilha(Pilha *pilha, char *nome, int id)
{
    Aluno *novo = malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->id = id;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}
void imprimi_fila(Fila *fila){
    Aluno *leitor;
    leitor = fila->inicio;
    while(leitor != NULL){
        printf("%d\n%f\n%f ", leitor->id, leitor->nota1, leitor->nota2);
        leitor = leitor->proximo;
    }
}

void imprimi_pilha_nomes(Pilha *pilha)
{
    Aluno *leitor;
    leitor = pilha->topo;
    if (pilha->topo == NULL)
    {
        printf("A pilha dos alunos esta vazia");
    }
    else
    {
        while (leitor != NULL)
        {
            printf("%s\n", leitor->nome);
            leitor = leitor->proximo;
        }
    }
}

void imprimi_pilha(Pilha *pilha)
{
    Aluno *leitor;
    leitor = pilha->topo;
    if (pilha->topo == NULL)
    {
        printf("A pilha dos alunos esta vazia");
    }
    else
    {
        while (leitor != NULL)
        {
            printf("\nNome do aluno: %s\nID: %d\n", leitor->nome, leitor->id);
            leitor = leitor->proximo;
        }
    }
}
int examina_pilha(Pilha *pilha, int id)
{
    Aluno *leitor;
    leitor = pilha->topo;
    while (leitor != NULL)
    {
        if (leitor->id == id)
        {
            return 1;
            break;
        }
        else
        {
            return 0;
        }
        leitor = leitor->proximo;
    }
}

void gera_media_fila(Fila *fila, int id){
    Aluno *leitor;
    float media = 0;
    leitor = fila->inicio;
    while (leitor != NULL){
        if(leitor->id == id){
            media = leitor->nota1 + leitor->nota2;
            printf("media do aluno: %.1f\n", media/2);
        }
        leitor = leitor->proximo;   
    }
}

int contador_pilha(Pilha *pilha)
{
    Aluno *leitor;
    int contador = 0;
    leitor = pilha->topo;
    while (leitor != NULL)
    {
        contador = contador + 1;
        leitor = leitor->proximo;
    }
    contador++;
    return contador;
}

int main()
{
    Pilha *pilha_alunos = cria_pilha();
    Fila *fila_alunos = cria_fila();
    int opcao, escolha_id, resultado_id, media;
    float nota1, nota2;
    char nome[50];

    while (opcao != 7)
    {

        printf("\n1 - Cadastrar aluno\n2 - Cadastrar Nota\n3 - Calcular media do aluno\n4 - Listar os nomes dos alunos sem notas\n5 - Excluir aluno\n6 - Excluir nota\n7 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInsira o nome do aluno:\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ; // Limpa o buffer de entrada
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = 0; // Remove a nova linha do final da string
            insere_pilha(pilha_alunos, nome, contador_pilha(pilha_alunos));
            printf("Aluno cadastrado com sucesso!!\n\n");
            break;
        case 2:
            imprimi_pilha(pilha_alunos);
            printf("\nInforme o ID do aluno ao qual deseja inserir uma nota:\n");
            scanf("%d", &escolha_id);
            resultado_id = examina_pilha(pilha_alunos, escolha_id);
            if(resultado_id == 1)
            {
                printf("\nAluno encontrado!!\n");
                printf("Escolha a primeira nota do aluno:\n");
                scanf("%f", &nota1);
                
                printf("Escolha a segunda nota do aluno:\n");
                scanf("%f", &nota2);
                insere_fila(fila_alunos, nota1, nota2, escolha_id);
                
            }
            else
            {
                printf("\nAluno nao encontrado\n");
            }

            break;
        case 3:
            printf("Informe o ID do aluno que deseja visualizar a media");
            scanf("%d", &media);
            gera_media_fila(fila_alunos, media);

        case 4:
            printf("\nLista dos alunos cadastrados\n");
            imprimi_pilha_nomes(pilha_alunos);
            break;
        case 5:
            break;
        
        default:
            break;
        }
    }
}