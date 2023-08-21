#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

// Estrutura de cada nó da lista
typedef struct node{
    int val;
    struct node *next;
} Node;


// Estrutura da lista
typedef struct lista{
    Node *inicio;
    Node *fim;
    int size;
} Lista;


// Função que cria a lista
Lista *lista_criar()
{
    Lista *L = (Lista*) malloc(sizeof(Lista));

    L->inicio = NULL;
    L->fim    = NULL;
    L->size   = 0;

    return L;
}


// Função que criar os nós da lista
Node *node_criar(int val)
{
    Node *no = (Node*) malloc(sizeof(Node));

    no->val  = val;
    no->next = NULL;

    return no; 
}


// Função que imprimi a lista 
void lista_imprimir(Lista *L)
{
    Node *aux = L->inicio;

    while(aux != NULL)
    {
        printf("%d -> ", aux->val);
        aux = aux->next;
    }
    printf("NULL\n"); 
    printf("Tamanho: %d\n", L->size);
}


// Função que verifica se a lista está vazia
bool lista_vazia(Lista *L)
{
    return L->size == 0;
}


// Função que insere no início da lista
void lista_adiciona_inicio(Lista *L, int val)
{
    Node *no = node_criar(val);
    no->next = L->inicio;

    // Caso em que a lista está vazia, início e fim vão ser iguais
    if(lista_vazia(L))
    {
        L->fim = no;
    }

    L->inicio = no;
    L->size++;
}


// Função que adiciona um valor no fim da lista
void lista_adiciona_fim(Lista *L, int val)
{
    Node *no = node_criar(val);
    
    if(lista_vazia(L))
    {
        L->inicio = no;
        L->fim    = no;
    }

    else {
        L->fim->next = no;
        L->fim = no;
    }

    L->size++; 
}


// Função que dado um valor remove o nó que possui esse valor
void lista_remove(Lista *L, int val)
{
    if(!lista_vazia(L))
    {
        Node *anterior = NULL;
        Node *atual    = L->inicio;
        
        while(atual != NULL && atual->val != val)
        {
            anterior = atual;
            atual    = atual->next;
        }

        if(atual != NULL)
        {
            
            if(L->fim == atual)
            {
                L->fim = anterior;  
            }

            if(L->inicio == atual)
            {
                L->inicio = L->inicio->next;
            }

            else {
                anterior->next = atual->next;
            }

            free(atual);
        }

        L->size--;
    }
}


// Função que desaloca uma lista
void lista_destroi(Lista **L_ref)
{
    puts("Destroi\n");

    Lista *L = *L_ref;

    Node *atual = L->inicio;
    Node *aux   = NULL;

    while(atual != NULL)
    {
        aux = atual;
        atual = atual->next;
        free(aux);
    }

    free(L);

    L_ref = NULL;
}