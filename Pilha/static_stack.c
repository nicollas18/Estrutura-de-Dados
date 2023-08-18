#include "static_stack.h"

typedef struct _static_stack
{
    int *data;
    long capacity;
    long top;
} StaticStack;

StaticStack *StaticStack_create(long capacity)
{
    StaticStack *S = (StaticStack*) malloc(sizeof(StaticStack));

    S->data = (int*) malloc(capacity * sizeof(int));
    S->capacity = capacity;
    S->top = -1;

    return S;
}

void StatickStack_destroy(StaticStack **S_ref)
{
    StaticStack *S = *S_ref;

    free(S->data);
    free(S);

    *S_ref = NULL;
}

bool StaticStack_is_empty(StaticStack *S)
{
    return S->top == -1;
}

bool StaticStack_is_full(StaticStack *S)
{
    return S->top == S->capacity - 1;
}

void StaticStack_push(StaticStack *S, int val)
{
    if(StaticStack_is_full(S))
    {
        printf("A pilha esta cheia\n");
        return;
    }

    S->top++;
    S->data[S->top] = val;
}

int StaticStack_peek(StaticStack *S)
{
    if(StaticStack_is_empty(S))
    {
        printf("A pilha está vazia\n");
        return 0;
    }

    return S->data[S->top];
}

int StaticStack_pop(StaticStack *S)
{
    if(StaticStack_is_empty(S))
    {
        printf("A pilha está vazia\n");
        return 0;
    }

    int val;

    val = S->data[S->top];
    S->top--;

    return val;
}

void StaticStack_print(StaticStack *S)
{
    printf("capacity: %ld\n", S->capacity);
    printf("top: %ld\n", S->top);

    for(long i = S->top; i >= 0; i--)
    {
        printf("%d\n", S->data[i]);
    }
}
