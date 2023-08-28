#ifndef GRAPH_H
#define GRAPH_H

typedef struct node Node;
typedef struct graph Graph;

Graph *graph_create(int vertices);
Node *node_create(int vertice);
int isEmpty(Graph *G, int indice);
void addEdge(Graph *G, int origem, int destino);
void dfsUtil(Graph *G, int vertice, int vistiados[]);
void dfs(Graph *G, int origem);
void bfs(Graph *G, int origem);

#endif