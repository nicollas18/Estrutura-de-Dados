#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct tree *left;
    struct tree *right;

} Node;


Node *node_create(int value)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->value = value;
    new_node->left  = NULL;
    new_node->right = NULL;

    return new_node;
}

Node *node_insert(Node *root, int value)
{
    if(root == NULL)
    {
        Node *new_node = node_create(value);

        return new_node;
    }

    if(value > root->value)
    {
        root->right = node_insert(root->right, value);
    }
    else {
        root->left = node_insert(root->left, value);
    }

    return root;
}

Node *node_remove(Node *root, int value)
{
    if(root == NULL)
    {
        return root;
    }

    else {

        if(root->value == value)
        {
            if(root->left == NULL && root->right == NULL)
            {
                free(root);

                return NULL;
            }

            else {

                if(root->left == NULL)
                {
                    Node *aux = root;
                    root = root->right;
                    aux->right = NULL;
                    free(aux);
                }

                else if(root->right == NULL)
                {
                    Node *aux = root;
                    root = root->left;
                    aux->left = NULL;
                    free(aux);
                }

                else {

                    Node *current  = root->left;
                    Node *previous = NULL;

                    while(current->right != NULL)
                    {
                        previous = current;
                        current  = current->right;
                    }

                    root->value = current->value;

                    if(previous == NULL)
                    {
                        root->left = NULL;
                        free(current);
                    }
                    else{

                        previous->right = current->left;
                        free(current);
                    }
                }

                return root; 
            }
        }
        else{

            if(value > root->value)
            {
                root->right = node_remove(root->right, value);
            }
            else{
                root->left = node_remove(root->left, value);
            }

            return root;
        }
    }
}

void print_in_order(Node *root)
{
    printf("(");

    if(root != NULL)
    {
        print_in_order(root->left);
        printf(", %d ,", root->value);
        print_in_order(root->right);
        
    }

    printf(")");
}

void print_pre_order(Node *root)
{
    printf("(");

    if(root != NULL)
    {
        printf(" %d ", root->value);
        print_pre_order(root->left);
        print_pre_order(root->right);
        
    }

    printf(")");
}

void print_pos_order(Node *root)
{
    printf("(");

    if(root != NULL)
    {
        print_pos_order(root->left);
        print_pos_order(root->right);
        printf(" %d ", root->value);
        
    }

    printf(")");
}

