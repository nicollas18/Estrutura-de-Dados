#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int          vertice;
    struct node *proximo;

} Node;


typedef struct graph 
{
    int    vertices;
    int     arestas;
    Node **adjLists;

} Graph;

Graph *graph_create(int vertices)
{
    Graph *G = (Graph*) malloc(sizeof(Graph));

    G->vertices = vertices;
    G->arestas  = 0;

    G->adjLists = (Node**) malloc(vertices * sizeof(Node*));

    for(int i = 0; i < vertices; i++)
    {
        G->adjLists[i] = NULL;
    }

    return G;
}

Node *node_create(int vertice)
{
    Node *N = (Node*) malloc(sizeof(Node));

    N->vertice = vertice;
    N->proximo = NULL;

    return N;
}

int isEmpty(Graph *G, int indice)
{
    return G->adjLists[indice] == NULL;
}

void addEdge(Graph *G, int origem, int destino)
{
    if(origem >= 0 && origem < G->vertices && destino >= 0 && destino < G->vertices)
    {
        Node *N = node_create(destino);

        N->proximo          = G->adjLists[origem];
        G->adjLists[origem] = N;
        G->arestas++;
    }
}

void dfsUtil(Graph *G, int vertice, int vistiados[])
{
    vistiados[vertice] = 1;

    Node *atual = G->adjLists[vertice];

    while(atual != NULL)
    {
        int adjVertice = atual->vertice;

        if(!vistiados[adjVertice])
        {
            dfsUtil(G, adjVertice, vistiados);
        }

        else {
            atual = atual->proximo;
        }
    }
}

void dfs(Graph *G, int origem)
{
    int *visitados = (int*) calloc(G->vertices, sizeof(int));

    printf("Iniciando Busca em Profundida(DFS) pelo vertíce %d: ", origem);
    dfsUtil(G, origem, visitados);
    printf("\n");
    free(visitados);

}

void bfs(Graph *G, int origem)
{
    int *visitados = (int*) calloc(G->vertices, sizeof(int));
    int fila[G->vertices];
    int inicio = 0, fim = 0;

    printf("Iniciando Busca em Largura(BFS) pelo vertíce %d: ", origem);

    visitados[origem] = 1;
    fila[fim++] = origem;

    while(inicio != fim)
    {
        int vertice = fila[fim++];
        printf("%d ", vertice);

        Node *atual = G->adjLists[vertice];

        while(atual != NULL)
        {
            int adjVertice = atual->vertice;

            if(!visitados[adjVertice])
            {
                visitados[adjVertice] = 1;
                fila[fim++] = 1;
            }
            else {
                atual = atual->proximo;
            }
        }
    }

    printf("\n");
    free(visitados);
}