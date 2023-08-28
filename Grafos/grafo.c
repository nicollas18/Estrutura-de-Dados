#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjLists;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int source, int destination) {
    struct Node* newNode = createNode(destination);
    newNode->next = graph->adjLists[source];
    graph->adjLists[source] = newNode;
}

void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        printf("Adjacências do vértice %d: ", i);
        struct Node* current = graph->adjLists[i];
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node* current = graph->adjLists[i];
        while (current != NULL) {
            struct Node* nextNode = current->next;
            free(current);
            current = nextNode;
        }
    }
    free(graph->adjLists);
    free(graph);
}

void dfsUtil(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* current = graph->adjLists[vertex];
    while (current != NULL) {
        int adjVertex = current->vertex;
        if (!visited[adjVertex]) {
            dfsUtil(graph, adjVertex, visited);
        }
        else {
            current = current->next;
        }
        
    }
}

void dfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->vertices, sizeof(int));
    printf("DFS starting from vertex %d: ", startVertex);
    dfsUtil(graph, startVertex, visited);
    printf("\n");
    free(visited);
}

void bfs(struct Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->vertices, sizeof(int));
    int queue[graph->vertices];
    int front = 0, rear = 0;

    printf("BFS starting from vertex %d: ", startVertex);
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        struct Node* current = graph->adjLists[vertex];
        while (current != NULL) {
            int adjVertex = current->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            else {
                current = current->next;
            }
            
        }
    }

    printf("\n");
    free(visited);
}

int main() {
    int vertices = 7;
    struct Graph* graph = createGraph(vertices);

    /*
    addEdge(graph, 0, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 0, 7);
    addEdge(graph, 1, 3);
    addEdge(graph, 7, 9);
    addEdge(graph, 8, 6);
    addEdge(graph, 9, 5);
    addEdge(graph, 4, 0);
    addEdge(graph, 9, 8);
    addEdge(graph, 1, 9);
    addEdge(graph, 2, 0);
    addEdge(graph, 1, 8);
    addEdge(graph, 8, 9);
    addEdge(graph, 0, 6);
    addEdge(graph, 8, 4);
    addEdge(graph, 5, 7);
    addEdge(graph, 2, 4);
    addEdge(graph, 0, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 5);
    */
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);

    printf("Listas de adjacência:\n");
    printGraph(graph);

    dfs(graph, 0);
    bfs(graph, 0);

    freeGraph(graph);

    return 0;
}
