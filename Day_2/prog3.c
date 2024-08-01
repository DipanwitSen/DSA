#include <stdio.h>
/* Name -Dipanwita sen
   Roll-22052204
   Sec -40 */
void binary_Search(int target, int low, int high, int a[], int *c) {
    if (low > high) {
        printf("Target not found.\n");
        return;
    }

    int mid = (low + high) / 2;
    (*c)++;

    if (target == a[mid]) {
        printf("Found at index %d with %d comparisons.\n", mid, *c);
        return;
    }
    else if (target < a[mid]) {
        binary_Search(target, low, mid - 1, a, c);
    }
    else {
        binary_Search(target, mid + 1, high, a, c);
    }
}

int main() {
   printf("Name=Dipanwita \n
           Sec=40 \n
           Roll=220522404 \n");
    int n, target;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter array elements in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);

    int comparisons = 0;
    binary_Search(target, 0, n - 1, arr, &comparisons);

    return 0;
}
