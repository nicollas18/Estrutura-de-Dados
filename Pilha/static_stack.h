#ifndef STAICK_STACH_h
#define STAICK_STACH_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _static_stack StaticStack;

StaticStack *StaticStack_create(long capacity);
void StatickStack_destroy(StaticStack **S_ref);

bool StaticStack_is_empty(StaticStack *S);
bool StaticStack_is_full(StaticStack *S);

void StaticStack_push(StaticStack *S, int val);
int StaticStack_peek(StaticStack *S);
int StaticStack_pop(StaticStack *S);

void StaticStack_print(StaticStack *S);

#endif 