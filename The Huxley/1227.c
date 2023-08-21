#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int element;
    struct _node* next;
} NODE;

typedef struct _stack
{
    NODE* head;
} STACK;

//Cria uma stack com o a head NULL
STACK* Create_stack()
{
    STACK *S = (STACK*) malloc(sizeof(STACK));

    S->head = NULL;

    return S;
}

//Recebe um elemento e cria e retorna um novo node
// com o elemento passado
NODE* create_node(int element)
{
    NODE *new_node = (NODE*) malloc(sizeof(NODE));

    new_node->element = element;
    new_node->next    = NULL;

    return new_node;
}

//Verifica se a pilha esta vazia
int IS_EMPTY(STACK* stack)
{
    return stack->head == NULL;
}

//Recebe uma pilha e Retorna o elemento que esta no topo da fila
int POP(STACK* stack)
{
    if(IS_EMPTY(stack))
    {
        return -1;
    }

    int value = stack->head->element;
    NODE *aux = stack->head;

    stack->head = stack->head->next;

    free(aux);

    return value;
}

//Recebe uma pilha e um inteiro e retorna a nova pilha
//Adiciona um novo node no topo da pilha
void PUSH(STACK* stack, int element)
{
    NODE *new_node = create_node(element);

    new_node->next = stack->head;
    stack->head    = new_node;
}

//Recebe a pilha e a operacao a ser feita
//faz a operacao da calculadora
void result(STACK* stack, char operation)
{
    int value;

    if(operation == '+')
    {
        if(stack->head->next != NULL)
        {
            value = stack->head->next->element + stack->head->element;
            POP(stack);
            POP(stack); 
            PUSH(stack, value);
        }  
    }

    else if(operation == '-')
    {
        if(stack->head->next != NULL)
        {
            if(stack->head->next->element > stack->head->element)
            {
                value = stack->head->next->element - stack->head->element;
            }
            else {
                value = stack->head->element - stack->head->next->element;
            }
        
            POP(stack);
            POP(stack);
            PUSH(stack, value);
        }
    }

    else if(operation == '*')
    {
        if(stack->head->next != NULL)
        {
            value = stack->head->next->element * stack->head->element;
            POP(stack);
            POP(stack);
            PUSH(stack, value); 
        }
    }

    else if(operation == '/')
    {
        if(stack->head->next != NULL)
        {
            if(stack->head->next->element > stack->head->element)
            {
                value = stack->head->next->element / stack->head->element;
            }
            else {
                value = stack->head->element / stack->head->next->element;
            }
        
            POP(stack);
            POP(stack);
            PUSH(stack, value);
        }
    }
}

//Recebe uma pilha vazia e quantas strings serao lidas
//Le as n strings que vao seguir e resolve as expressoes
void Calculadora(STACK* calculadora, int size)
{
    for(int i = 0; i < size; i++)
    {
        int number;
        char string[10];
        scanf(" %[^\n]", string);
        //printf("%c\n", string[0]);

        if(string[0] != '+' && string[0] != '-' && string[0] != '*' && string[0] != '/')
        {
            number = atoi(string);
            //printf("%d\n", number);
            PUSH(calculadora, number);
        }
        else {
            result(calculadora, string[0]);
        }
    }
}

int main()
{
    STACK* calculadora = Create_stack();
    int k;
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 1: %d\n", POP(calculadora));
    scanf("%d", &k);
    Calculadora(calculadora, k);
    printf("Coordenada 2: %d\n", POP(calculadora));

}