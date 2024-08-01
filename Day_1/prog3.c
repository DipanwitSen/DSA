//previous sum
/* Name -Dipanwita sen
   Roll-22052204
   Sec -40 */
#include <stdio.h>
int main() {
   printf("Name=Dipanwita \n
           Sec=40 \n
           Roll=220522404 \n");
    int a[100], b[100], n;
    
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    b[0] = a[0];
    printf("%d ", b[0]);  // Print the first element of b
    
    for (int i = 1; i < n; i++) {
        b[i] = b[i-1] + a[i];
        printf("%d ", b[i]);
    }
    
    printf("\n");  // Add a newline at the end for better formatting
    
    return 0;
}
