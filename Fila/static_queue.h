#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

#include <stdbool.h>

typedef struct _static_queue StaticQueue;

StaticQueue *StaticQueue_create(long capacity);
void StaticQueue_destroy(StaticQueue **q_ref);

bool StaticQueue_is_empty(StaticQueue *Q);
bool StaticQueue_is_full(StaticQueue *Q);
long StaticQueue_size(StaticQueue *Q);

void StaticQueue_enqueue(StaticQueue *Q, int val);
int StaticQueue_peek(StaticQueue *Q);
int StaticQueue_dequeue(StaticQueue *Q);

void StaticQueue_print(StaticQueue *Q);

#endif