#include<stdio.h>
#include<stdlib.h>

// Swap function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (a[start] <= pivot && start < end) {
            start++;
        }
        while (a[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

// Quicksort function
void quick(int a[], int lb, int ub) {
    if (lb < ub) {
        int loc = partition(a, lb, ub);
        quick(a, lb, loc - 1);
        quick(a, loc + 1, ub);
    }
}

int main() {
    int *a, n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    a = (int*)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Call the quicksort function
    quick(a, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Free allocated memory
    free(a);
    return 0;
}
