#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct _simple_node {
    int val;
    struct simple_node *next;

} SimpleNode;

typedef struct _linked_list{
    SimpleNode *begin;
    SimpleNode *end;

} LinkedList;

bool LinkedList_is_empty(const LinkedList *L)
{
    return (L->begin == NULL && L->end == NULL);
}

LinkedList *LinkedList_create()
{
    LinkedList *list;
    list = (LinkedList*) malloc(sizeof(LinkedList));

    list->begin = NULL;
    list->end = NULL;

    return list;
}

SimpleNode *SimpleNode_create(int val)
{
    SimpleNode *snode;
    snode = (SimpleNode*) malloc(sizeof(SimpleNode));

    snode->val = val;
    snode->next = NULL;

    return snode;
}

void LinkedList_add_frist(LinkedList *L, int val)
{
    SimpleNode *snode = SimpleNode_create(val);
    snode->next = L->begin;

    if(LinkedList_is_empty(L))
    { 
        L->end = snode;
    }

    L->begin = snode;

    /* 

    Código Otimizado

    SimpleNode *snode;
    snode = SimpleNode_create(val);

    snode->next = L->begin;
    L->begin = snode;

    */
}

void LinkedList_add_last(LinkedList *L, int val)
{

    SimpleNode *snode = SimpleNode_create(val);

    if(LinkedList_is_empty(L))
    {
        L->begin = snode;
        L->end = snode;

    } else {

        L->end->next = snode;
        L->end = snode;
    }
}

void LinkedList_add_last_slow(LinkedList *L, int val)
{

    SimpleNode *snode = SimpleNode_create(val);

    if(LinkedList_is_empty(L))
    {
        L->begin = snode;

    } else {

        SimpleNode *p = L->begin;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = snode;
    }   
}


void LinkedList_print(LinkedList *L)
{
    SimpleNode *p;
    p = L->begin;

    while(p != NULL)
    {
        printf("%d\n", p->val);
        p = p->next;
    }
}


