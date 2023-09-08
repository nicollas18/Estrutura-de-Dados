#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int          value;
    struct node  *left;
    struct node *right;

} Node;

typedef struct tree
{
    Node *root;
    int   size;
     
} Tree;

Tree *tree_create()
{
    Tree *root = (Tree*) malloc(sizeof(Tree));

    root->root = NULL;
    root->size = 0;

    return root;
}

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
    if (root == NULL)
    {
        Node *new_node = node_create(value);
        return new_node;
    }

    if(value < root->value)
    {
        root->left = node_insert(root->left, value);
    }
    else {
        root->right = node_insert(root->right, value);
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

int main()
{
    Tree *tree = tree_create();

    tree->root = node_insert(tree->root, 15);
    tree->size++;
    tree->root = node_insert(tree->root, 10);
    tree->size++;
    tree->root = node_insert(tree->root, 20);
    tree->size++;
    tree->root = node_insert(tree->root, 5);
    tree->size++;
    tree->root = node_insert(tree->root, 25);
    tree->size++;

    print_in_order(tree->root);
    

    return 0;
}