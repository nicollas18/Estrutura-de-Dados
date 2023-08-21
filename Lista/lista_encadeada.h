#ifndef LISTA_ENCADEADA
#define LISTA_ENCADEADA
#include <stdbool.h>

typedef struct node Node;
typedef struct lista Lista;

// Cria uma lista
Lista *lista_criar();

// Cria um nó
Node *node_criar(int val);

// Imprimi a lista
void lista_imprimir(Lista *L);

// Checa se a lista está vazia
bool lista_vazia(Lista *L);

// Adiciona um valor no início da lista
void lista_adiciona_inicio(Lista *L, int val);

// Adiciona um valor no fim da lista
void lista_adiciona_fim(Lista *L, int val);

// Remove um determinado nó da lista
void lista_remove(Lista *L, int val);

// Destroi uma lista
void lista_destroi(Lista **L_ref);

#endif