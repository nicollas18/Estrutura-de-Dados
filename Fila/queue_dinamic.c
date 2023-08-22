#include "dinamic_queue.h"
#include <stdio.h>

int main(){

    DinamicQueue *Q = DinamicQueue_create();

    printf("enqueue:\n");
    DinamicQueue_enqueue(Q, 10);
    DinamicQueue_enqueue(Q, 20);
    DinamicQueue_enqueue(Q, 30);
    DinamicQueue_enqueue(Q, 40);
    DinamicQueue_print(Q);

    printf("peek\n");
    printf("%d\n", DinamicQueue_peek(Q));
    DinamicQueue_print(Q);

    printf("dequeue\n");
    DinamicQueue_dequeue(Q);
    DinamicQueue_dequeue(Q);
    DinamicQueue_print(Q);

    return 0;
    
}
