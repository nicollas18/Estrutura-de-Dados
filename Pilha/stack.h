#ifndef STAICK_h
#define STAICK_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _node Node;
typedef struct _stack Stack;

Stack *Stack_create();
Node *Node_Create(int val);
//void Stack_add_node(Stack *S, int val);
void Stack_destroy(Stack **S_ref);

bool Stack_is_empty(Stack *S);
bool Stack_is_full(Stack *S);

void Stack_push(Stack *S, int val);
int Stack_peek(Stack *S);
int Stack_pop(Stack *S);

void Stack_print(Stack *S);

#endif 