#ifndef DINAMIC_HASH_H
#define DINAMIC_HASH_H

typedef struct node Node;
typedef struct hash Hash;

// cria a tabela hash
Hash *Hash_Create();

// cria o nó
Node *Node_Create();

// função de hash
int hash(int key);

// inseri um dado valor
void Hash_Put(Hash *H, int key, int value);

// imprimi a tabela
void Hash_Print(Hash *H);

// libera memória da tabela
void Hash_free(Hash *H);


#endif