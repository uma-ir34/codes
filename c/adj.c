#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Define a structure for the adjacency list
typedef struct {
    Node* head;
} AdjList;

// Function to create a new node in the adjacency list
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the adjacency list
void addEdge(AdjList* adjList, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = adjList[src].head;
    adjList[src].head = newNode;
}

// Function to display the adjacency list
void displayAdjList(AdjList* adjList, int vertices) {
    printf("Adjacency List:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Vertex %d: ", i);
        Node* current = adjList[i].head;
        while (current != NULL) {
            printf("%d -> ", current->vertex);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to create and display the adjacency matrix
void displayAdjMatrix(int** adjMatrix, int vertices) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    // Create an array of adjacency lists
    AdjList* adjList = (AdjList*)malloc(vertices * sizeof(AdjList));

    // Initialize the adjacency lists
    for (int i = 0; i < vertices; ++i) {
        adjList[i].head = NULL;
    }

    // Create an adjacency matrix
    int** adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; ++i) {
        adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; ++j) {
            adjMatrix[i][j] = 0;
        }
    }

    // Input edges and build the graph
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        addEdge(adjList, src, dest);
        adjMatrix[src][dest] = 1;
    }

    // Display the adjacency list and adjacency matrix
    displayAdjList(adjList, vertices);
    displayAdjMatrix(adjMatrix, vertices);

    // Free the allocated memory before exiting
    for (int i = 0; i < vertices; ++i) {
        Node* current = adjList[i].head;
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
        free(adjMatrix[i]);
    }
    free(adjList);
    free(adjMatrix);

    return 0;
}
