#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef enum {NoEsquerdo, NoDireito, NoPai, NoRaiz} DIRECAO;

typedef struct {
    TIPOCHAVE chave;
//    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *esq;
    struct estrutura *dir;
    struct estrutura *pai;

} ARVORE_BINARIA;


// Inicializa a arvore binaria deixando-a pronta para ser utilizada.
void inicializar(ARVORE_BINARIA *arvore)
{
    arvore = NULL;
}


// Retorna true se a arvore esta vazia (igual a NULL)
bool vazia(ARVORE_BINARIA *arvore)
{
    return arvore == NULL;
}


// Cria um novo no usando o apontador arvore passado contendo o item,
// os apontadores para o pai e para os filhos contendo NULL
void criarNo(ITEM item, ARVORE_BINARIA **arvore)
{
    if (!vazia(*arvore))
    {
       printf("ERRO: O no deve estar vazio para ser criado.");
       exit(EXIT_FAILURE);
    }

    *arvore = (ARVORE_BINARIA*) malloc(sizeof(ARVORE_BINARIA));
    (*arvore)->item = item;
    (*arvore)->pai = NULL;
    (*arvore)->esq = NULL;
    (*arvore)->dir = NULL;
}


// Testa se o No indicado por Direcao a partir de arv existe
bool existeNo(DIRECAO direcao, ARVORE_BINARIA *arvore)
{
   if (vazia(arvore))
      return false;

   if (direcao == NoRaiz)
      return true;
   
   if (direcao == NoPai)
      return !vazia(arvore->pai);

   if (direcao == NoEsquerdo)
      return !vazia(arvore->esq);

   if (direcao == NoDireito)
      return !vazia(arvore->dir);

   return false;
}



// Cria um filho no NO apontado por Arvore na direcao informada
bool adicionarFilho(ITEM item, DIRECAO direcao, ARVORE_BINARIA *arvore)
{
   if (vazia(arvore) || (direcao == NoPai) || (direcao == NoRaiz) || existeNo(direcao, arvore))
     return false;  // Criacao ilegal de um filho

   if (direcao == NoEsquerdo)
   {
       criarNo(item, &(arvore->esq));
       arvore->esq->pai = arvore;
   }
   else
   {
       criarNo(item, &(arvore->dir));
       arvore->dir->pai = arvore;
   }
   return true;
}



// Desaloca da memoria toda a arvore
void disposeArvore(ARVORE_BINARIA *arvore)
{
   if (!vazia(arvore))
   {
      disposeArvore(arvore->esq);
      disposeArvore(arvore->dir);
      free(arvore);
   }
}

/*************************************************************/
// Caso precise de alguma funcao auxiliar, criar aqui

/*typedef struct node Node;
typedef struct list List;

List *list_create();
Node *node_create(int value);
void adicionar_na_lista(List *list, int elem);
bool pertence_a_lista(List *lista, int elem);
bool verifica_com_lista(ARVORE_BINARIA *arvore, List *lista);*/


typedef struct list
{
    int value;
    struct list *next;

} List;

List node_list(int value)
{
    List *list = (List*) malloc(sizeof(List));

    list->value = value;
    list->next  = NULL; 

    return list;

}

List node_add_list(List *list, int value)
{
    List *l = node_list(value);

    l->next = list;
}


void adicionar_na_lista(List *list, int elem)
{
    Node *new_node = node_create(elem);

    if(list->begin == NULL)
    {
        list->begin = new_node;
    }
    
    else {

        new_node->next = list->begin;
        list->begin = new_node;
    } 
}


bool pertence_a_lista(List *lista, int elem)
{
    Node *aux = lista->begin;

    while (aux != NULL && aux->elem != elem)
        aux = aux->next;
    

    if (aux != NULL)
        return true;

    return false;
}



bool verifica_com_lista(ARVORE_BINARIA *arvore, List *lista)
{
    
    if (arvore == NULL)
    {
        //printf("teste\n");
        return false;
    }
  

    if (pertence_a_lista(lista, arvore->item.chave))
    {
        return true;
    }
    else
    {
        adicionar_na_lista(lista, arvore->item.chave);

        bool v = verifica_com_lista(arvore->esq, lista);

        if (v == false)
            v = verifica_com_lista(arvore->dir, lista);

        return v;
    }
    
}

/*************************************************************/


/*
| Objetivos: Percorre a arvore e analisa, para cada NO da arvore apontada
|            pelo parametro arvore, se ha algum outro NO com o mesmo valor
|            de chave. Se houver, retorna true. Caso contrario, retorna false.
*/
bool haDuplicados(ARVORE_BINARIA *arvore, ARVORE_BINARIA *raiz)
{
    List *lista = list_create(arvore->item.chave);
    return verifica_com_lista(arvore, lista);
}


/////////////////////////////////////////////////////

// Mostra na tela uma linha informando se ha valores duplicados na Arvore
void imprimirSeHaDuplicados(ARVORE_BINARIA *arv) {
   if (haDuplicados(arv, arv))
      printf("Ha valores duplicados\n");
   else
      printf("Nao ha valores duplicados\n");
}

/////////////////////////////////////////////////////

int main()
{
   ARVORE_BINARIA *arv1 = NULL;
   inicializar(arv1);

   ITEM item;
   item.chave = 1;
   criarNo(item, &arv1); // cria o no Raiz
   imprimirSeHaDuplicados(arv1);

   item.chave = 2;
   adicionarFilho(item, NoEsquerdo, arv1);

   item.chave = 5;
   adicionarFilho(item, NoDireito, arv1);
   /*
                 1
              2     5
   */

   item.chave = 3;
   adicionarFilho(item, NoEsquerdo, arv1->esq);

   item.chave = 4;
   adicionarFilho(item, NoDireito, arv1->esq);

   item.chave = 6;
   adicionarFilho(item, NoEsquerdo, arv1->dir);

   item.chave = 7;
   adicionarFilho(item, NoDireito, arv1->dir->esq);
   
/*
                                1
                             2     5
                            3 4   6
                                   7
*/
   imprimirSeHaDuplicados(arv1);

   item.chave = 1;
   adicionarFilho(item, NoEsquerdo, arv1->esq->esq);

   imprimirSeHaDuplicados(arv1);

   item.chave = 7;
   adicionarFilho(item, NoDireito, arv1->dir);
   imprimirSeHaDuplicados(arv1);
/*
                                  1
                             2         5
                           3   4     6   7
                         1         7
*/

   disposeArvore(arv1);
   return 0;
}
