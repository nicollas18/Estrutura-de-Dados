#include "linked_list.h"

int main(){

    LinkedList *list;
    list = LinkedList_create();

    /*
    LinkedList_add_frist(list, 5);
    LinkedList_add_frist(list, 4);
    LinkedList_add_frist(list, 2);
    LinkedList_add_frist(list, 10);
    */

    LinkedList_add_last(list,10);
    LinkedList_add_last(list,2);
    LinkedList_add_last(list,7);
    LinkedList_add_last(list,5);
    LinkedList_add_last(list,7);

    LinkedList_print(list);

    printf("O primeiro valor da lista é: %d\n", LinkedList_frist_val(list));
    printf("O último valor da lista é: %d\n", LinkedList_last_val(list));
    printf("O valor que está na posição 2 é: %d\n", LinkedList_get_val(list, 2));

    return 0;
}
