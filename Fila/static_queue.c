#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "static_queue.h"

typedef struct _static_queue
{
    int *data;
    long capacity;
    long size;
    long begin;
    long end;

} StaticQueue;

StaticQueue *StaticQueue_create(long capacity)
{
    StaticQueue *Q = (StaticQueue*) malloc(sizeof(StaticQueue));
    Q->capacity = capacity;

    Q->data  = (int*) malloc(capacity * sizeof(int));
    Q->size  = 0;
    Q->begin = 0;
    Q->end   = 0;

    return Q;
}
void StaticQueue_destroy(StaticQueue **q_ref)
{
    StaticQueue *Q = *q_ref;

    free(Q->data);
    free(Q);

    *q_ref = NULL;
}

bool StaticQueue_is_empty(StaticQueue *Q)
{
    return Q->size == 0;
}

bool StaticQueue_is_full(StaticQueue *Q)
{
    return Q->size == Q->capacity;
}
long StaticQueue_size(StaticQueue *Q)
{
    return Q->size;
}

void StaticQueue_enqueue(StaticQueue *Q, int val)
{
    if(StaticQueue_is_full(Q))
    {
        printf("A fila está cheia\n");
        exit(EXIT_FAILURE);
    }

    Q->data[Q->end] = val;
    Q->end = (Q->end + 1) % Q->capacity; // lista circular
    Q->size++;


}

int StaticQueue_peek(StaticQueue *Q)
{
    if(StaticQueue_is_empty(Q))
    {
        printf("A lista está vazia\n");
        exit(EXIT_FAILURE);
    }

    return Q->data[Q->begin];
}

int StaticQueue_dequeue(StaticQueue *Q)
{
    if(StaticQueue_is_empty(Q))
    {
        printf("A lista está vazia\n");
        exit(EXIT_FAILURE);
    }

    int val = Q->data[Q->begin];
    Q->begin = (Q->begin + 1) % Q->capacity; // lista circular
    Q->size--;

    return val;
}

void StaticQueue_print(StaticQueue *Q) {
    printf("capacity: %ld\n", Q->capacity);
    printf("size: %ld\n", Q->size);
    printf("begin: %ld\n", Q->begin);
    printf("end: %ld\n\n", Q->end);

    long s, i;

    for (s = 0, i = Q->begin;
         s < Q->size;
         s++, i = (i + 1) % Q->capacity) {
        printf("%d, ", Q->data[i]);
    }
    puts("");
}
