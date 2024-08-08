#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub) {
    int pivot = a[ub];
    int i = lb - 1;     
    for (int j = lb; j <= ub - 1; j++) {
        if (a[j] < pivot) {
            i++; 
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[ub]);
    return (i + 1);
}

void quick_sort(int a[], int p, int r) {
    if (p < r) {
        int loc = partition(a, p, r);
        quick_sort(a, p, loc - 1);
        quick_sort(a, loc + 1, r);
    }
}

int main() {
    srand(time(NULL));
    int *a, n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        printf("Enter element of array index %d: ", i);
        scanf("%d", &a[i]);
    }
    int r = rand() % n;
    printf("Random number from array: %d\n", a[r]);
    swap(&a[r], &a[n-1]); 

    quick_sort(a, 0, n - 1);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
