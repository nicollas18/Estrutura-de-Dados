#include "static_queue.h"
#include <stdio.h>

int main()
{
    StaticQueue *Q = StaticQueue_create(5);
    int val;

    puts("enqueue: 10, 20, 30");

    StaticQueue_enqueue(Q, 10);
    StaticQueue_enqueue(Q, 20);
    StaticQueue_enqueue(Q, 30);
    StaticQueue_print(Q);

    puts("\npeek");
    val = StaticQueue_peek(Q);
    printf("%d\n", val);
    StaticQueue_print(Q);

    puts("\ndequeue");
    val = StaticQueue_dequeue(Q);
    printf("%d\n", val);
    StaticQueue_print(Q);

}