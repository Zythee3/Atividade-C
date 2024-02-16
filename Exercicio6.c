#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{
    char nome[50];
    int id, nota;
    struct Aluno *proximo;
} Aluno;

typedef struct Pilha
{
    Aluno *topo;
} Pilha;

Pilha *cria_pilha()
{
    Pilha *novo = malloc(sizeof(Pilha));
    novo->topo = NULL;
    return novo;
}

void insere_pilha(Pilha *pilha, char *nome, int id)
{
    Aluno *novo = malloc(sizeof(Aluno));
    strcpy(novo->nome, nome);
    novo->id = id;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

void imprimi_pilha(Pilha *pilha){
    Aluno *leitor;
    leitor = pilha->topo;
    while (leitor != NULL){
        printf("\nNome do aluno: %s\nID: %d\n", leitor->nome, leitor->id);
        leitor = leitor->proximo;
    }
}


int contador_pilha(Pilha *pilha){
    Aluno *leitor;
    int contador = 0;
    leitor = pilha->topo;
    while(leitor != NULL){
        contador = contador + 1;
        leitor = leitor->proximo;
    }
    contador++;
    return contador;
}


int main()
{
    Pilha *pilha_alunos = cria_pilha();
    int opcao;
    char nome[50];
    
    while(opcao != 6){
        opcao = 0;
        printf("\n1 - Cadastrar aluno\n2 - Cadastrar Nota\n3 - Calcular media do aluno\n4 - Listar os nomes dos alunos sem notas\n5 - Excluir aluno\n6 - Excluir nota\n7 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInsira o nome do aluno:\n");
            scanf("%s", &nome);
            insere_pilha(pilha_alunos, nome, contador_pilha(pilha_alunos));
            printf("Aluno cadastrado com sucesso!!\n\n");
            break;
        case 2:
            imprimi_pilha(pilha_alunos);
        default:
            break;
        }
    }
}