#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

// Estrutura de um nó da lista
typedef struct _doubly_node Node;

// Estrutura de uma lista
typedef struct _doubly_linked_list List;

// Função que cria uma lista
List *List_create();

// Função que cria um nó da lista
Node *Node_create(int val);

// Função que destroi uma lista
void List_destroy(List **L_ref);

// Função que verifica se uma lista está vazia
bool List_is_empety(List *L);

// Função que imprimi uma lista
void List_print(List *L);

// Função que imprimi uma lista na ordem inversa
void Lists_print_inverse(List *L);

// Função que adiciona um nó no início da lista
void List_add_frist(List *L, int val);

// Função que adiciona um nó no fim da lista
void List_add_last(List *L, int val);



#endif