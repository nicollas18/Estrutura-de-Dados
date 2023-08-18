#include "static_stack.h"

int main(){

    StaticStack *S = StaticStack_create(5);
    int top_val;

    StaticStack_print(S);

    top_val = StaticStack_peek(S);
    printf("top_val = %d\n", top_val);

    top_val = StaticStack_pop(S);
    printf("top_val = %d\n", top_val);

    StaticStack_push(S, 10);
    StaticStack_push(S, 20);
    StaticStack_push(S, 30);
    StaticStack_push(S, 40);
    StaticStack_push(S, 50);

    StaticStack_print(S);

    StaticStack_pop(S);
    StaticStack_pop(S);
    StaticStack_pop(S);

    StaticStack_print(S);

    return 0;
}