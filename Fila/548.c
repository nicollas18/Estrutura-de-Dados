#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node *next;

} NODE;

typedef struct list
{
    NODE *begin;
    NODE *end;
    int size;

} LIST;

typedef struct stack
{
    LIST *top;
    int size;

} STACK;

STACK *stack_create()
{
    STACK *S = (STACK*) malloc(sizeof(STACK));

    S->top  = NULL;
    S->size = 0;

    return S;
}

LIST *list_create()
{
    LIST *L = (LIST*) malloc(sizeof(LIST));

    L->begin = NULL;
    L->end   = NULL;
    L->size  = 0;

    return L;
}

NODE *node_create(int val)
{
    NODE *N = (NODE*) malloc(sizeof(NODE));

    N->val  = val;
    N->next = NULL;

    return N;
}

void list_add_last(LIST *L, int val)
{
    NODE *N = node_create(val);

    if(L->size == 0)
    {
        L->begin = N;
    }
    else {
        L->end->next = N;
    }

    L->end = N;
    L->size++;
}

int main(){

    STACK *S = stack_create();
    LIST *L  = list_create();

    char s[5];

    while(1)
    {
        if(scanf("%[^\n]", s) == EOF)
        {
            break;
        }

        if(s[1] == 'U')
        {
            while(1)
            {
                int number;
                char c;

                scanf("%d", &number);
                list_add_last(L, number);

                scanf("%c", &c);

                if(c == '\n') break;
            }

            S->top = L;
        }

        else if(s[1] == 'O')
        {

        }
    }

}