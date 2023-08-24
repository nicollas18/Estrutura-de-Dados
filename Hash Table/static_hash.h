#ifndef STATIC_HASH_H     
#define STATIC_HASH_H

typedef struct _static_hash StaticHash;

StaticHash *StaticHash_create(int capacity);
int function_hash(int key, int capacity);
void StaticHash_put(StaticHash *H, int value);
int StaticHash_search_key(StaticHash *H, int key);
void StaticHash_print(StaticHash *H);

#endif