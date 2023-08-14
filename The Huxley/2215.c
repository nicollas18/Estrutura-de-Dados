#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    char number;
    struct node *prev;
    struct node *next;
} Node;

typedef struct lista{
    Node *begin;
    Node *end;
} Lista;

Lista *list_creat()
{
    Lista *L = (Lista*) malloc(sizeof(Lista));

    L->begin = NULL;
    L->end   = NULL;

    return L;
}

Node *node_create(char val)
{
    Node *no = (Node*) malloc(sizeof(Node));

    if(no == NULL)
    {
        printf("ERROR IN MEMORY\n");
        exit(1);
    }

    no->number = val;
    no->next   = NULL;
    no->prev   = NULL;

    return no;
}


void Node_add_frist(Lista *L, char val)
{
    Node *no = node_create(val);
    no->next = L->begin;

    if(L->end == NULL && L->begin == NULL)
    { 
        L->end = no;
    }

    L->begin = no;
    
}

void Node_add_last(Lista *L, char val)
{
    Node *no = node_create(val);

    if(L->begin == NULL && L->end == NULL)
    {
        L->begin = no;
    }

    else {
        no->prev = L->end;
        L->end->next = no;
    }

    L->end   = no;
}

void List_print(Lista *L)
{
    Node *atual = L->begin;

    while(atual != NULL)
    {
        printf("%c -> ", atual->number);
        atual = atual->next;
    }
    printf("NULL\n");
}

void somar(Lista *L1, Lista *L2, Lista *L3)
{
    Node *atual_L1 = L1->end;
    Node *atual_L2 = L2->end;
    int soma;


    while(atual_L1 != NULL && atual_L2 != NULL)
    {
        soma = ((int)atual_L1->number % (int)'0') + ((int)atual_L2->number % (int)'0');
        Node_add_frist(L3, soma);

        atual_L1 = atual_L1->prev;
        atual_L2 = atual_L2->prev;
    }
}

int main(){

    int contador_L1 = 0, contador_L2 = 0;

    Lista *L1 = list_creat();
    Lista *L2 = list_creat();
    Lista *L3 = list_creat();

     while(1)
    {
        char number, verefic;
        scanf("%c%c", &number, &verefic);

        // caso da lista 1 está vazia
        if(number == '+' && verefic == '\n'){
            break;
        }
        else{

            Node_add_last(L1, number);
            contador_L1++;

            if(verefic == '\n')
            {
                char operacao;
                scanf("%c", &operacao);

                if(operacao == '+') break;
            }
        }

      
    }

     while(1)
    {
        char number, verefic;
        scanf(" %c%c", &number, &verefic);

        // caso da lista 2 está vazia
        if(number == '=' && verefic == '\n'){
            break;
        }
        else{

            Node_add_last(L2, number);
            contador_L2++;

            if(verefic == '\n')
            {
                char operacao;
                scanf("%c", &operacao);

                if(operacao == '=') break;
            }
        }
      
    }

    somar(L1,L2,L3);

    //printf("%d\n%d\n", contador_L1, contador_L2);

    if (contador_L1 == 0 && contador_L2 == 0)
    {
        printf("Lista Vazia!\n");
    }
    else {
        List_print(L3);
    }

    
    

    return 0;
}