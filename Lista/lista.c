#include <stdio.h>
#include "lista_encadeada.h"

int main(){

    Lista *L;
    L = lista_criar();

    lista_adiciona_fim(L, 0);
    lista_imprimir(L);
    
    lista_adiciona_fim(L, 5);
    lista_imprimir(L);
    
    lista_adiciona_fim(L, 10);
    lista_imprimir(L);
    
    lista_adiciona_fim(L, 15);
    lista_imprimir(L);
    
    lista_adiciona_fim(L, 20);
    lista_imprimir(L);

    lista_remove(L,20);
    lista_imprimir(L);

    //LinkedList_remove(L,20);
    //lista_imprimir(L);

    lista_destroi(&L);

    return 0;
}