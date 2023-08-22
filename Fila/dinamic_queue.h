#ifndef DINAMIC_QUEUE_H
#define DINAMIC_QUEUE_H

#include <stdbool.h>

typedef struct _dinamic_queue DinamicQueue;

DinamicQueue *DinamicQueue_create();
void DinamicQueue_destroy(DinamicQueue **q_ref);

bool DinamicQueue_is_empty(DinamicQueue *Q);
long DinamicQueue_size(DinamicQueue *Q);

void DinamicQueue_enqueue(DinamicQueue *Q, int val);
int DinamicQueue_peek(DinamicQueue *Q);
int DinamicQueue_dequeue(DinamicQueue *Q);

void DinamicQueue_print(DinamicQueue *Q);

#endif
