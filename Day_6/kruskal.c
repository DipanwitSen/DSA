#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int u, v, w;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to find set of an element u (uses path compression)
int find(struct Subset subsets[], int u) {
    if (subsets[u].parent != u) {
        subsets[u].parent = find(subsets, subsets[u].parent);
    }
    return subsets[u].parent;
}

// Function to union two sets of u and v (uses union by rank)
void Union(struct Subset subsets[], int u, int v) {
    int rootU = find(subsets, u);
    int rootV = find(subsets, v);

    // Attach smaller rank tree under root of the higher rank tree
    if (subsets[rootU].rank < subsets[rootV].rank) {
        subsets[rootU].parent = rootV;
    } else if (subsets[rootU].rank > subsets[rootV].rank) {
        subsets[rootV].parent = rootU;
    } else {
        subsets[rootV].parent = rootU;
        subsets[rootU].rank++;
    }
}

// Function to compare two edges based on their weight
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->w - edgeB->w;
}

// Function to implement Kruskal's algorithm
void KruskalMST(struct Edge edges[], int n, int m) {
    struct Subset* subsets = (struct Subset*)malloc(n * sizeof(struct Subset));
    struct Edge* result = (struct Edge*)malloc((n - 1) * sizeof(struct Edge)); // Store the MST
    int e = 0; // Index for result
    int i = 0; // Index for sorted edges

    // Initialize subsets (each node is its own parent and rank 0)
    for (int v = 0; v < n; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Sort edges by weight
    qsort(edges, m, sizeof(struct Edge), compareEdges);

    // Process edges in increasing order of weight
    while (e < n - 1 && i < m) {
        struct Edge nextEdge = edges[i++]; // Pick the smallest edge
        int u = find(subsets, nextEdge.u);
        int v = find(subsets, nextEdge.v);

        // If including this edge doesn't cause a cycle
        if (u != v) {
            result[e++] = nextEdge; // Include the edge in MST
            Union(subsets, u, v);   // Union the sets
        }
    }

    // Print the MST and total cost
    printf("Selected edges of the Minimum Spanning Tree:\n");
    int totalCost = 0;
    for (i = 0; i < e; i++) {
        printf("Edge: %d - %d \tWeight: %d\n", result[i].u + 1, result[i].v + 1, result[i].w);
        totalCost += result[i].w;
    }
    printf("Total cost of MST: %d\n", totalCost);

    // Free memory
    free(subsets);
    free(result);
}

int main() {
    int n, m;
    printf("Enter the number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    struct Edge* edges = (struct Edge*)malloc(m * sizeof(struct Edge));

    printf("Enter the edges (u v w) with nodes numbered from 1 to %d:\n", n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        edges[i].u--; // Convert to 0-indexed for internal processing
        edges[i].v--; // Convert to 0-indexed for internal processing
    }

    KruskalMST(edges, n, m);

    // Free memory
    free(edges);
    return 0;
}
