#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define V 6 // Maximum number of vertices

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int vertex, int weight) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph with V vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->adjList = (struct Node**)malloc(vertices * sizeof(struct Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(struct Graph* graph, int start) {
    int dist[V];
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = 1;

        struct Node* neighbor = graph->adjList[u];
        while (neighbor != NULL) {
            int v = neighbor->vertex;
            int weight = neighbor->weight;
            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
            neighbor = neighbor->next;
        }
    }

    printSolution(dist);
}

int main() {
    struct Graph* graph = createGraph(V);

    printf("Enter the number of edges: ");
    int numEdges;
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        printf("Enter edge (source destination weight): ");
        scanf("%d %d %d", &source, &destination, &weight);

        if (source < 0 || source >= V || destination < 0 || destination >= V) {
            printf("Invalid source or destination vertex. Should be between 0 and %d.\n", V - 1);
            return 1;
        }

        struct Node* newNode = createNode(destination, weight);
        newNode->next = graph->adjList[source];
        graph->adjList[source] = newNode;
    }

    int start;
    printf("Enter the source vertex: ");
    scanf("%d", &start);

    if (start < 0 || start >= V) {
        printf("Invalid source vertex. Should be between 0 and %d.\n", V - 1);
        return 1;
    }

    dijkstra(graph, start);

    return 0;
}
