#include "static_hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _static_hash 
{
    int    *data;
    int capacity;

} StaticHash;

StaticHash *StaticHash_create(int capacity)
{
    StaticHash *H = (StaticHash*) malloc(sizeof(StaticHash));

    H->data = (int*) malloc(capacity * sizeof(int));
    H->capacity = capacity;
    
    return H;
}

int function_hash(int key, int capacity)
{
    return key % capacity;
}

void StaticHash_put(StaticHash *H, int value)
{
    int id = function_hash(value, H->capacity);

    while (H->data[id] != 0)
    {
        id = function_hash(id + 1, H->capacity);
    }

    H->data[id] = value;
}

int StaticHash_search_key(StaticHash *H, int key)
{
    int id = function_hash(key, H->capacity);
    
    while (H->data[id] != 0)
    {
        if(H->data[id] == key)
            return H->data[id];

        else
            id = function_hash(id + 1, H->capacity);
    }

    return 0;
}

void StaticHash_print(StaticHash *H)
{
    int i;

    for(i = 0; i < H->capacity; i++)
    {
        printf("%d = %d\n", i, H->data[i]);
    }
}