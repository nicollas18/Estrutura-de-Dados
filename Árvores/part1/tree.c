#include "binary_tree.h"
#include <stdio.h>

int main()
{
    Binary_Tree *tree = NULL;

    insert_node_binary_tree(&tree, 100);
    insert_node_binary_tree(&tree, 200);
    insert_node_binary_tree(&tree, 300);
    insert_node_binary_tree(&tree, 400);

    print_in_order(tree);
    //print_pre_order(tree);
    //print_post_order(tree);

    return 0;
}