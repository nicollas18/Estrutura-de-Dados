#include "static_hash.h"
#include <stdio.h>

int main(){

    int size, r;
    scanf("%d", &size);

    StaticHash *H = StaticHash_create(size);

    StaticHash_put(H, 10);
    StaticHash_put(H, 20);
    StaticHash_put(H, 30);
    StaticHash_put(H, 40);

    StaticHash_print(H);

    r = StaticHash_search_key(H, 10);


    if(r != 0)
    {
        printf("chave encontrada!\n");
    }
    else{
        printf("chave não encontrada\n");
    }

    return 0;

}