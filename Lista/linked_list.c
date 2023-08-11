#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct _simple_node {
    int val;
    struct _simple_node *next;

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

void LinkedList_remove_v1(LinkedList *L, int val)
{
    // caso 1: o elemento está na cabeça 
    if(!LinkedList_is_empty(L))
    {
        
        if(L->begin->val == val)
        {
            SimpleNode *pos = L->begin;

            //A lista possui apenas um nó
            // es este nó será removido 
            if(L->begin == L->end)
            {
                L->end = NULL;
            }

            L->begin = L->begin->next;
            free(pos);

        } 

        // caso 2: o elemento está no meio da lista
        // Caso 3 - remoção do final

        else {

            SimpleNode *prev = L->begin;
            SimpleNode *pos = L->begin->next;

            /*

            Enquanto a lista ainda tiver elementos para percorer/checar e o valor do nó  apontado pelo ponterio 'pos' for diferente  do valor desejado avance os
            ponteiros axuliares (prev e pos) para os próximos nós da lista.
            */

            while(pos != NULL && pos->val != val)
            {
                prev = prev->next;
                pos = pos->next;
            }

            // O valor foi encontrado
            if(pos != NULL)
            {
                prev->next = pos->next;

                // Se o elemento a ser removido é o último nó da lista
                
                if(pos->next == NULL)
                {
                    L->end = prev;
                }
            }

            free(pos);
        }
    }
}

void LinkedList_remove(LinkedList *L, int val)
{
    if(!LinkedList_is_empty(L))
    {
        SimpleNode *prev = NULL;
        SimpleNode *pos = L->begin;

        while(pos != NULL && pos->val != val)
        {
            prev = pos;
            pos = pos->next;
        }

        if(pos != NULL)
        {
            if(L->end == pos)
            {
                L->end = prev;
            }

            if(L->begin == pos)
            {
                L->begin = L->begin->next;
            }

            else {
                prev->next = pos->next;
            }

            free(pos);
        }
    }
}

void LinkedList_remove_all(LinkedList *L, int val)
{
    if(!LinkedList_is_empty(L))
    {
        SimpleNode *prev = NULL;
        SimpleNode *pos = L->begin;
        SimpleNode *aux = NULL;

        while(pos != NULL)
        {

            if(pos->val == val)
            {
                if(L->end = pos)
                {
                    L->end = prev;
                }

                if(L->begin = pos)
                {
                    L->begin = L->begin->next;
                }

                else {
                    prev->next = pos->next;  
                }

            }

            else {
                prev = pos;
                pos = pos->next;

            }
        }
    }
}

void LinkedList_print(LinkedList *L)
{
    SimpleNode *p;
    p = L->begin;

    while(p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");
}




