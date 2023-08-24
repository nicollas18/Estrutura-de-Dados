#include "dinamic_hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int   key;
    int value;

} Node;

typedef struct hash{
    Node   **table;
    long capacity;

} Hash;

Hash *Hash_Create(int capacity)
{
    Hash *H = (Hash*) malloc(sizeof(Hash));

    H->table = (Node*) malloc(capacity * sizeof(Node));

    for(int i = 0; i < capacity; i++)
    {
        H->table[i] = NULL;
    }
}