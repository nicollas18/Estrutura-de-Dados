#ifndef LINKED_LIST
#define LINKED_LIST
#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>

typedef struct _simple_node SimpleNode;
typedef struct _linked_list LinkedList;

LinkedList *LinkedList_create();
void LinkedList_destroy(LinkedList **L_ref);
SimpleNode *SimpleNode_create(int val);
bool LinkedList_is_empty(const LinkedList *L);
void LinkedList_add_frist(LinkedList *L, int val);
void LinkedList_add_last(LinkedList *L, int val);
void LinkedList_add_last_slow(LinkedList *L, int val);
void LinkedList_remove_v1(LinkedList *L, int val);
void LinkedList_remove(LinkedList *L, int val);
void LinkedList_remove_all(LinkedList *L, int val);
void LinkedList_print(LinkedList *L);
size_t LinkedList_size(LinkedList *L);
int LinkedList_frist_val(LinkedList *L);
int LinkedList_last_val(LinkedList *L);
int LinkedList_get_val(LinkedList *L, int index);

#endif
