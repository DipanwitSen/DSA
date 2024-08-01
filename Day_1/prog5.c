//right rotation 
/* Name -Dipanwita sen
   Roll-22052204
   Sec -40 */
#include <stdio.h>
void EXCHANGE(int *A, int p, int q) {
    int temp = A[p];
    A[p] = A[q];
    A[q] = temp;
}

void ROTATE_RIGHT(int *A, int b) {
    if (b < 1) return;  
    int temp = A[b - 1];
    for (int i = b - 1; i > 0; i--) {
        A[i] = A[i - 1];
    }
    A[0] = temp;
}

int main() {
   printf("Name=Dipanwita \n
           Sec=40 \n
           Roll=220522404 \n");
    int A[100], n, b;
    printf("Enter size of array: ");
    scanf("%d", &n);
    printf("Enter elements of array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Enter rotation place: ");
    scanf("%d", &b);
    
    printf("\nBefore Rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    ROTATE_RIGHT(A, b);
    
    printf("\nAfter Rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
