#include "linked_list.h"

int main(){

    LinkedList *list;
    list = LinkedList_create();

    
    LinkedList_add_frist(list, 5);
    LinkedList_add_frist(list, 4);
    LinkedList_add_frist(list, 2);
    LinkedList_add_frist(list, 10);
    


    /*
    LinkedList_add_last(list,5);
    LinkedList_add_last(list,4);
    LinkedList_add_last(list,2);
    LinkedList_add_last(list,10);
    */
    

    
    LinkedList_print(list);
    
    return 0;
}