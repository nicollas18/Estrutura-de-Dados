#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Estrutura do nó de uma lista
typedef struct _doubly_node{
    int val;
    struct _doubly_node *prev;
    struct _doubly_node *next;
} Node;

// Estrutura da lista
typedef struct _doubly_linked_list{
    Node *begin;
    Node *end;
    size_t size;
} List;


//Cria uma lista
List *List_create()
{
    List *L = (List*) malloc(sizeof(L));

    L->begin = NULL;
    L->end   = NULL;
    L->size  = 0;

    return L;
}

// Cria um nó da lista
Node *Node_create(int val)
{
    Node *no = (Node*) malloc(sizeof(Node));

    no->val  = val;
    no->prev = NULL;
    no->next = NULL;

    return no;
}

// Destroi uma lista
void List_destroy(List **L_ref)
{

    puts("destroy");

    List *L = *L_ref;

    Node *p = L->begin;
    Node *aux = NULL;

    while(p != NULL)
    {
        aux = p;
        p   = p->next;

        free(aux);
    }
    free(L);

    *L_ref = NULL;
}

// Função que verifica se uma lista está vazia
bool List_is_empety(List *L)
{
    return L->size == 0;
}

// Imprimi a lista
void List_print(List *L)
{
    Node *atual = L->begin;

    while(atual != NULL)
    {
        printf("%d -> ", atual->val);
        atual = atual->next;
    }
    printf("NULL\n");
    printf("Size: %ld\n", L->size);
}

// Imprimi a lista na ordem inversa
void Lists_print_inverse(List *L)
{
    Node *atual = L->end;

    while(atual != NULL)
    {
        printf("%d -> ", atual->val);
        atual = atual->prev;
    }
    printf("NULL\n");
    printf("Size: %ld\n", L->size);
}

// Adiciona um nó no início da lista
void List_add_frist(List *L, int val)
{
    Node *no = Node_create(val);
    no->next = L->begin;

    if(List_is_empety(L))
    {
        L->end = no;
    }

    else {
        L->begin->prev = no;
    }

    L->begin = no;
    L->size++;
}

// Adiciona no fim da lista
void List_add_last(List *L, int val)
{
    Node *no = Node_create(val);
    no->prev = L->end;

    if(List_is_empety(L))
    {
        L->begin = no;
    }

    else {
        L->end->next = no;
    }
    
    L->end = no;
    L->size++;
}

// Remove um nó da lista
void List_remove(List *L, int val)
{
    if(!List_is_empety(L))
    {
        Node *atual = L->begin;

        // caso 1: o elmento está na cabeça da lista
        if(L->begin->val == val)
        {
            L->begin = atual->next;

            // a lista possui apenas um elemento
            if(L->end == atual)
            {
                L->end = NULL;
            }
            // a lista possui mais de um elemento
            else{
                L->begin->prev = NULL;
            }

            free(atual);
            L->size--;
        }

        // caso 2: o elemento está no meio da lista
        // caso 3: o elemento está no final da lista
        
        else {
            atual = atual->next;

            while(atual != NULL)
            {
                if(atual->val == val)
                {
                    atual->prev->next = atual->next;

                    // caso 3:
                    if(L->end == atual)
                    {
                        L->end = atual->prev;
                    }
                    // caso 2:
                    else {
                        atual->next->prev = atual->prev;
                    }

                    free(atual);
                    atual = NULL;
                    L->size--;
                }

                else {
                    atual = atual->next;
                }  
            }
        }     
    }
}
