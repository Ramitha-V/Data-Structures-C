#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph {
    int numVertices;
    struct node** adjLists;
};

struct Graph* createGraph(int vertices) {
    if (vertices <= 0) {
        printf("Number of vertices should be greater than 0. Exiting.\n");
        exit(1);
    }

    struct Graph* graph = malloc(sizeof(struct Graph));
    if (graph == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    if (graph->adjLists == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->numVertices || dest >= graph->numVertices) {
        printf("Invalid source or destination. Please try again.\n");
        return;
    }

    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (src != dest) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deleteNode(struct Graph* graph, int src, int dest) {
    if (src < 0 || dest < 0 || src >= graph->numVertices || dest >= graph->numVertices) {
        printf("Invalid source or destination. Please try again.\n");
        return;
    }

    struct node* temp = graph->adjLists[src];
    struct node* prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Edge does not exist\n");
        return;
    }
    if (prev == NULL)
        graph->adjLists[src] = temp->next;
    else
        prev->next = temp->next;
    free(temp);

    if (src != dest) {
        temp = graph->adjLists[dest];
        prev = NULL;
        while (temp != NULL && temp->vertex != src) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
            graph->adjLists[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    printf("Edge between %d and %d has been deleted\n", src, dest);
}

int main() {
    int vertices, choice, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    struct Graph* graph = createGraph(vertices);

    while (1) {
        printf("\n1. Add Edge\n2. Delete Edge\n3. Print Graph\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter source and destination: ");
                scanf("%d %d", &src, &dest);
                addEdge(graph, src, dest);
                break;
            case 2:
                printf("Enter source and destination to delete edge: ");
                scanf("%d %d", &src, &dest);
                deleteNode(graph, src, dest);
                break;
            case 3:
                printGraph(graph);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}