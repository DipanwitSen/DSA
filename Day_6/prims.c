#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the MST stored in parent[]
void printMST(int parent[], int graph[MAX][MAX], int V) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to calculate and display the total cost of MST
int totalCostMST(int parent[], int graph[MAX][MAX], int V) {
    int totalCost = 0;
    for (int i = 1; i < V; i++)
        totalCost += graph[i][parent[i]];
    return totalCost;
}

// Function to implement Prim's algorithm
void primMST(int graph[MAX][MAX], int V, int start) {
    int parent[MAX];  // Array to store the MST
    int key[MAX];     // Key values to pick the minimum weight edge
    bool mstSet[MAX]; // To represent the set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Starting vertex has key value 0
    key[start] = 0;
    parent[start] = -1; // Starting node is the root of the MST

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V); // Pick the minimum key vertex not in MST
        mstSet[u] = true;               // Add the picked vertex to the MST

        // Update key and parent for the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST and its total cost
    printMST(parent, graph, V);
    printf("Total cost of MST: %d\n", totalCostMST(parent, graph, V));
}

// Main function
int main() {
    int V;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix of the graph (enter 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Edge (%d, %d): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    int start_vertex;
    printf("Enter the starting vertex (0 to %d): ", V - 1);
    scanf("%d", &start_vertex);

    printf("Prim's Minimum Spanning Tree starting from vertex %d:\n", start_vertex);
    primMST(graph, V, start_vertex);

    return 0;
}
