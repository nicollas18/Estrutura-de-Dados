#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int data;
    enum Color color;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->color = RED; // Novos nós são sempre vermelhos
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    return newNode;
}

Node* insertNode(Node* root, int data);
void fixViolation(Node** root, Node* node);
void rotateLeft(Node** root, Node* node);
void rotateRight(Node** root, Node* node);
void inOrderTraversal(Node* root);
void freeTree(Node* root);

int main() {
    Node* root = NULL;

    root = insertNode(root, 55);
    root = insertNode(root, 40);
    root = insertNode(root, 65);
    root = insertNode(root, 60);
    root = insertNode(root, 75);

    printf("Árvore Red-Black em ordem: ");
    inOrderTraversal(root);
    printf("\n");

    freeTree(root);

    return 0;
}

Node* insertNode(Node* root, int data) {
    Node* newNode = createNode(data);

    if (root == NULL) {
        newNode->color = BLACK; // A raiz sempre é preta
        return newNode;
    }

    Node* current = root;
    Node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    fixViolation(&root, newNode);

    return root;
}

void fixViolation(Node** root, Node* node) {
    Node* parent = NULL;
    Node* grandparent = NULL;

    while ((node != *root) && (node->color == RED) && (node->parent->color == RED)) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->right) {
                    rotateLeft(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateRight(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        } else {
            Node* uncle = grandparent->left;

            if (uncle != NULL && uncle->color == RED) {
                parent->color = BLACK;
                uncle->color = BLACK;
                grandparent->color = RED;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                node = parent;
            }
        }
    }

    (*root)->color = BLACK;
}

void rotateLeft(Node** root, Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (node->right != NULL) {
        node->right->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == NULL) {
        *root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void rotateRight(Node** root, Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (node->left != NULL) {
        node->left->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == NULL) {
        *root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("(%d, %s) ", root->data, root->color == RED ? "Red" : "Black");
        inOrderTraversal(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
