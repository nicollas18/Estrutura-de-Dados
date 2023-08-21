#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

typedef struct pilha {
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isfull(TPilha *p) {
    return p->topo == TAM;
}

int isempty(TPilha *p) {
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) {
    if( isfull(p) ) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

void inverte_palavra(char s[]) {

    TPilha *pilha = (TPilha*) malloc(sizeof(TPilha));
    create(pilha);

    for(int i = 0; s[i] != '\0'; i++)
    {
        push(pilha, s[i]);
    }

    for(int i = pilha->topo; i != -1; i--)
    {
        s[pilha->topo - i] = pilha->vet[i];
    }
}

int main(void) {
    char palavra[TAM];

    scanf("%s", palavra);
    printf("original = %s\n", palavra);
    inverte_palavra(palavra);
    printf("invertida = %s\n", palavra);

    return 0;
}
