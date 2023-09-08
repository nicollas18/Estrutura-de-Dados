#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct  binary_tree 
{
    int value;
    struct binary_tree *left;
    struct binary_tree *right;

} Binary_Tree;

Binary_Tree *create_node_binary_tree(int value)
{
    Binary_Tree *new_node = (Binary_Tree*) malloc(sizeof(Binary_Tree));

    new_node->value = value;
    new_node->left  =  NULL;
    new_node->right =  NULL;

    return new_node;
}

Binary_Tree *insert_node_binary_tree(Binary_Tree **root, int value)
{
    Binary_Tree *aux = *root;

    while(aux != NULL)
    {
        if(value < aux->value)
        {
            root = &aux->left;
        }
        else {

            root = &aux->right;
        }

        aux = *root;
    }

    aux = (Binary_Tree*) malloc(sizeof(Binary_Tree));
    aux->value = value;
    aux->left = NULL;
    aux->right = NULL;
    *root = aux;

}

void print_in_order(Binary_Tree *root)
{
    if(root)
    {
        print_in_order(root->left);
        printf("%d", root->value);
        print_in_order(root->right);
    }
    //printf("\n");
}

void print_pre_order(Binary_Tree *root)
{
    if(root != NULL)
    {
        printf("%d", root->value);
        print_in_order(root->left);
        print_in_order(root->right);
    }
    //printf("\n");    
}

void print_post_order(Binary_Tree *root)
{
    if(root != NULL)
    { 
        print_in_order(root->left);
        print_in_order(root->right);
        printf("%d", root->value);
    }
    //printf("\n"); 
}