#include "stack.h"

typedef struct _node{
    int val;
    struct node *prev;
    struct node *next;
} Node;

typedef struct _stack
{
    Node *top;
} Stack;

Stack *Stack_create()
{
    Stack *new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top   = NULL;
    return new_stack;
}

Node *Node_create(int val)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->val  = val;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void Stack_push(Stack *S, int val){

    Node *new_node = Node_create(val);

    if(S->top == NULL)
    {
        S->top = new_node;
        return;
    }

    new_node->prev = S->top;
    S->top->next   = new_node;
    S->top         = new_node;
}

int Stack_peek(Stack *S)
{
    if(S->top == NULL)
    {
        printf("A pilha está vazia\n");
        return 0;
    }

    return S->top->val;
}

int Stack_pop(Stack *S)
{

    if(S->top == NULL)
    {
        printf("A pilha está vazia\n");
        return;
    }

    int val = S->top->val;
    Stack *aux;

    aux = S->top;
    S->top = S->top->prev;

    free(aux);
}

void Stack_print(Stack *S)
{
    Node *aux = S->top;

    if(S->top == NULL)
    {
        printf("A pilha está vazia\n");
        return;
    }

    while(aux != NULL)
    {
        printf("%d\n", aux->val);
        aux = aux->prev;
    }
}

