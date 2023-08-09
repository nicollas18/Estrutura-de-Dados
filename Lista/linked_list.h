#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>

typedef struct _simple_node SimpleNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
SimpleNode *SimpleNode_create(int val);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_frist(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_print(LinkedList *L);

#endif