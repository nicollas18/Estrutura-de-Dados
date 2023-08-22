#include "dinamic_queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int val;
    struct _node *prev;
    struct _node *next;

} Node;

typedef struct _dinamic_queue
{
    Node *begin;
    Node *end;
    long size;

} DinamicQueue;

DinamicQueue *DinamicQueue_create()
{
    DinamicQueue *Q = (DinamicQueue*) malloc(sizeof(DinamicQueue));

    Q->begin = NULL;
    Q->end   = NULL;
    Q->size  = 0;

    return Q;
} 

Node *Node_create(int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->val  = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void DinamicQueue_destroy(DinamicQueue **q_ref)
{
    DinamicQueue *Q = *q_ref;

    Node *p  = Q->begin;
    Node *aux = NULL;

    while(p != NULL)
    {
        aux = p;
        p   = p->next;
        free(aux);
    }

    free(Q);

    *q_ref = NULL;

}

bool DinamicQueue_is_empty(DinamicQueue *Q)
{
    return Q->size == 0;
}

long DinamicQueue_size(DinamicQueue *Q)
{
    return Q->size;
}

void DinamicQueue_enqueue(DinamicQueue *Q, int val)
{
    Node *new_node = Node_create(val);

    if(DinamicQueue_is_empty(Q))
    {
        Q->begin = new_node;
    }

    else {
        Q->end->next = new_node;
        new_node->prev = Q->end;

    }
    
    Q->end = new_node;
    Q->size++;
}

int DinamicQueue_peek(DinamicQueue *Q)
{
    return Q->begin->val;
}

int DinamicQueue_dequeue(DinamicQueue *Q)
{
    if(DinamicQueue_is_empty(Q))
    {
        printf("A fila está vaiza\n");
        exit(EXIT_FAILURE);
    }

    int val   = Q->begin->val;
    Node *aux = Q->begin;

    Q->begin = Q->begin->next;
    Q->begin->prev = aux->prev;

    free(aux);
    Q->size--;

    return val;

}

void DinamicQueue_print(DinamicQueue *Q)
{
    Node *aux = Q->begin;

    while(aux != NULL)
    {
        printf("%d ", aux->val);
        aux = aux->next;
    }

    printf("\n");
}
