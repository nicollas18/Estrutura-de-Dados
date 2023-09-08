#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node  *left;
    struct node *right;

} Node;

Node *build_tree(Node *root, char input[], int *contador)
{
    while (input[*contador] != '\0')
    {
        if (input[*contador] == '(')
        {
            (*contador)++;

            if ((int) input[*contador] <= 57 && (int) input[*contador] >= 48)
            {
                int number = 0;

                while (input[*contador] != '\0' && ((int) input[*contador] >=  48) && ((int) input[*contador] <= 57))
                {
                    number *= 10;
                    number += (int) input[*contador] - (int)'0';
                    (*contador)++;
                }

                root = (Node *) malloc(sizeof(Node));
                root->value = number;
                
                root->left = build_tree(root->left, input, contador);
                root->right = build_tree(root->right, input, contador);
                return root;
            }
            else if (input[*contador] == ')')
            {
                return root;
            }
        }

        (*contador)++;
    }

    return root;
}

Node *search(Node *root, int key)
{
    if(root == NULL || root->value == key)
    {
        return root;
    }

    if(key < root->value)
    {
        return search(root->left, key);
    }

    return search(root->right, key);
}

int altura_da_arvore(Node *root, int alt, int key)
{
    if(root == NULL || root->value == key)
    {
        return alt;
    }
    else {

        int alt1 = altura_da_arvore(root->left, alt+1, key);
        int alt2 = altura_da_arvore(root->right, alt+1, key);

        if(alt1 > alt2)
        {
            return alt1;
        }
        else {
            return alt2;
        }
    }
}

int main()
{
    int contador = 0;

    char input[100];
    scanf("%[^\n]", input);
    
    Node *root = build_tree(NULL, input, &contador);

    int number;
    scanf("%d", &number);

    Node *busca = search(root, number);
    int hight = altura_da_arvore(root, 0,  number);;

    if(busca == NULL)
    {
        printf("NAO ESTA NA ARVORE\n");
        printf("-1\n");
    }
    else{
        printf("ESTA NA ARVORE\n");
        printf("%d\n", hight);
    }


    return 0;
}