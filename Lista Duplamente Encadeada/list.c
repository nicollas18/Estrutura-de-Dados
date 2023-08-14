#include "linked_list.h"

#include <stdio.h>

int main(){

    List *L = List_create();

    List_add_last(L, 0);
    List_add_last(L, 5);
    List_add_last(L, 10);
    List_add_last(L, 15);
    List_add_last(L, 20);

    List_print(L);
    printf("\n");
    Lists_print_inverse(L);

    return 0;
}