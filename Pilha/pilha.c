#include "stack.h"

int main(){

    Stack *S = Stack_create();

    Stack_print(S);

    Stack_push(S, 10);
    Stack_push(S, 20);
    Stack_push(S, 30);
    Stack_push(S, 40);
    Stack_push(S, 50);

    Stack_print(S);

    Stack_pop(S);
    Stack_pop(S);
    Stack_pop(S);

    Stack_print(S);

    return 0;
}