#include "binary_tree.h"
#include <stdio.h>

int main()
{
    Node *root = node_create(14);

    root = node_insert(root, 18);
    root = node_insert(root, 8);
    root = node_insert(root, 10);
    root = node_insert(root, 5);
    root = node_insert(root, 16);
    root = node_insert(root, 20);
    root = node_insert(root, 19);
    root = node_insert(root, 6);
    root = node_insert(root, 7);
    root = node_insert(root, 6);

    printf("Em ordem: ");
    print_in_order(root);
    printf("\n");

    /*printf("Pré ordem: ");
    print_pre_order(root);
    printf("\n");

    printf("Pós ordem: ");
    print_pos_order(root);
    printf("\n");*/

    printf("\nRemove\n\n");
    root = node_remove(root, 20);
    root = node_remove(root, 19);
    root = node_remove(root, 8);

    printf("Em ordem: ");
    print_in_order(root);
    printf("\n");

    /*printf("Pré ordem: ");
    print_pre_order(root);
    printf("\n");

    printf("Pós ordem: ");
    print_pos_order(root);
    printf("\n"); */



    return 0;
}