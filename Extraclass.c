#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int idade;
  int prioridade;
  struct Node *prox;
} Node;

typedef struct Fila {
  Node *inicio;
  Node *fim;
} Fila;

Node *aux; // Ponteiro Auxiliar

Fila *CriarFila() {
  Fila *fila = (Fila *)malloc(sizeof(Fila));
  fila->inicio = NULL;
  fila->fim = NULL;
  return fila;
}

void Imprimir(Fila *fila) {

  aux = fila->inicio;

  printf("\n-------------------------------\n");
  while (aux != NULL) {
    printf(" %d ", aux->idade);
    aux = aux->prox;
  }
  printf("\n-------------------------------\n");
}

void insere_fila(Fila *fila, int idade) {
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->idade = idade;
  novo->prox = NULL;

  if (fila->inicio == NULL) {
    fila->inicio = novo;
    fila->fim = novo;
  } else {
    fila->fim->prox = novo;
    fila->fim = novo;
  }
  printf("\nPessoa com idade %d inserida na fila!\n", novo->idade);
}

void InserirComPrioridade(Fila *fila) {
  Node *novo = (Node *)malloc(sizeof(Node));

  int idade;
  printf("\nInforme a sua idade: ");
  scanf("%d", &idade);

  aux = fila->inicio;
  novo->idade = idade;
  if (idade >= 65) {
    if (fila->inicio->idade < 59) {
      novo->prox = fila->inicio;
      fila->inicio = novo;
      getchar();
    } else {
      while (aux != NULL && aux->prox->idade > 59) {
        aux = aux->prox;
      }
      novo->prox = aux->prox;
      aux->prox = novo;
      getchar();
    }
  } else {
    printf("\n\nA idade nao pode ser inserida na fila.");
    getchar();
  }
}





void remocao_elemento_prioridade(Fila *fi) {
  if (fi->inicio == NULL) {
    printf("Fila vazia\n");
  } else {
    aux = fi->inicio;
    fi->inicio = fi->inicio->prox;
    printf("\n\nO elemento de mais alta prioridade foi removido da fila.");
    free(aux);
  }
}

int main(void) {
  Fila *fi = CriarFila();
  int opcao;
  int idade;
  do {
    printf("\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\t4 - "
           "inserir com prioridade\n");
    scanf("%d", &opcao);
    char temp;
    scanf("%c", &temp);
    switch (opcao) {
    case 0:
      printf("Saindo...");
      break;
    case 1:
      printf("Digite sua sua idade:\n");
      scanf("%d", &idade);
      insere_fila(fi, idade);
      break;
    case 2:
      remocao_elemento_prioridade(fi);
      break;
    case 3:
      Imprimir(fi);
      break;
    case 4:
      InserirComPrioridade(fi);
      break;
    default:
      printf("\n\nValor invalido.");
      break;
    }

  } while (opcao != 0);

  return 0;
}

//