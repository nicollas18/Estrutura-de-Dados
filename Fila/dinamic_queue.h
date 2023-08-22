#ifndef DINAMIC_QUEUE_H
#define DINAMIC_QUEUE_H

#include <stdbool.h>

typedef struct _static_queue DinamicQueue;

DinamicQueue *Dinamic_Queue_create();
void DinamicQueue_destroy(DinamicQueue **q_ref);

bool Dinamic_Queue_is_empty(DinamicQueue *Q);
long Dinamic_Queue_size(DinamicQueue *Q);

void Dinamic_Queue_enqueue(DinamicQueue *Q, int val);
int Dinamic_Queue_peek(DinamicQueue *Q);
int Dinamic_Queue_dequeue(DinamicQueue *Q);

void Dinamic_Queue_print(DinamicQueue *Q);

#endif