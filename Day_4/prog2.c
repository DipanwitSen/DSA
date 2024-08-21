#include<stdio.h>

// Function prototypes
void min_heapify(int arr[], int n, int i);
void max_heapify(int arr[], int n, int i);

// Function to build a min-heap
void build_min_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(arr, n, i);
}

// Function to build a max-heap
void build_max_heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(arr, n, i);
}

int main() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    build_min_heap(arr, n);

    printf("Min-heap array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    build_max_heap(arr, n);

    printf("Max-heap array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
