#include<stdio.h>
#include<stdlib.h>

int main() {
    int *a, n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc(n * sizeof(int));
    if(a == NULL) {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}
