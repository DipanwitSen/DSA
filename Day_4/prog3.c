#include<stdio.h>

int main() {
    int a[100][100], n, m, c = 0;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &n);
    
    printf("Enter 1 if an edge exists, 0 if it doesn't exist:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("Does an edge exist between %d and %d? Enter 1 for yes or 0 for no: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (a[i][j] == 1 && a[j][i] == 1) { 
                printf("The graph is not one-way connected.\n");
                return 0;
            }
        }
    }

    printf("The graph is one-way connected.\n");
    return 0;
}
