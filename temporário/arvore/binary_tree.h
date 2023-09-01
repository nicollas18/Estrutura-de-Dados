#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node Node;

Node *node_create(int value);
Node *node_insert(Node *root, int value);

Node *node_remove(Node *root, int value);

void print_in_order(Node *root);
void print_pre_order(Node *root);
void print_pos_order(Node *root);



#endif