#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1; // Stack top index

// Depth-first search function
void dfs(int graph[][MAX_VERTICES], int vertex, int numVertices) {
    printf("%d ", vertex); // Print the current vertex
    visited[vertex] = true;

    // Push the current vertex onto the stack
    stack[++top] = vertex;

    // Traverse adjacent vertices
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(graph, i, numVertices);
        }
    }

    // Pop the current vertex from the stack
    // and print the pop order
    printf("(%d popped) ", stack[top--]);
}

int main() {
    int numVertices, startVertex;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    int graph[MAX_VERTICES][MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    printf("Depth First Search Traversal:\n");
    dfs(graph, startVertex, numVertices);

    return 0;
}
