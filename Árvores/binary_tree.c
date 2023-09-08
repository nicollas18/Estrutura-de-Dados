#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int conteudo;
    struct node *esquerda;
    struct node  *direita;

} Node;

typedef struct binary_tree
{
    Node *raiz;

} Binary_Tree;

Binary_Tree *tree_create()
{
    Binary_Tree *arvore = (Binary_Tree*) malloc(sizeof(Binary_Tree));

    arvore->raiz = NULL;

    return arvore;
}

Node *node_create(int valor)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->conteudo = valor;
    new_node->esquerda = NULL;
    new_node->direita  = NULL;

    return new_node;
}

Node *insert_tree(Node *raiz, int valor)
{
    if(raiz == NULL)
    {
        Node *new_node = (Node*) malloc(sizeof(Node));

        new_node->esquerda = NULL;
        new_node->direita  = NULL;

        return new_node;
    }

    else {

        if(valor < raiz->conteudo)
            return raiz->esquerda = insert_tree(raiz->esquerda, valor);

        else{
            return raiz->direita = insert_tree(raiz->direita, valor);
        }
    }
}

void imprimir (Node *arvore)
{
    if(arvore != NULL)
    {
        printf("%d ", arvore->conteudo);
        imprimir(arvore->esquerda);
        imprimir(arvore->direita);
    }
}

int main()
{
    Binary_Tree *arvore = tree_create();

    arvore->raiz = insert_tree(arvore->raiz, 5);
    arvore->raiz = insert_tree(arvore->raiz, 6);
    arvore->raiz = insert_tree(arvore->raiz, 4);
    arvore->raiz = insert_tree(arvore->raiz, 3);
    arvore->raiz = insert_tree(arvore->raiz, 7);

    imprimir(arvore->raiz);
    printf("\n");
}

