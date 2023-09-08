#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct binary_tree Binary_Tree;

Binary_Tree *create_node_binary_tree(int value);
Binary_Tree *insert_node_binary_tree(Binary_Tree **root, int value);

void print_in_order(Binary_Tree *root);
void print_pre_order(Binary_Tree *root);
void print_post_order(Binary_Tree *root);

#endif