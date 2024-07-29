#include<stdio.h>
#include<stdlib.h> // Required for malloc

int main() {
    int *a, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Correct memory allocation
    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection sort algorithm
    for (int i = 0; i < n - 1; i++) {//no of pass
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    // Print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Free allocated memory
    free(a);
    return 0;
}
