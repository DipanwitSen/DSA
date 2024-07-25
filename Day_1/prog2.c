#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void advancedBubbleSort(int arr[], int n, FILE *fp) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        int s = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                s = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (s == 0)
            break;

        // Print the array after each pass
        fseek(fp, 0, SEEK_END); // move pointer to end of file
        fprintf(fp, "Array after pass %d: ", i+1);
        for (int k = 0; k < n; k++) {
            fprintf(fp, "%d ", arr[k]);
        }
        fprintf(fp, "\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);
    if (n < 2) {
        printf("Array should have at least two elements\n");
        fclose(fp);
        return 1;
    }

    int *b = (int*)malloc(n * sizeof(int));
    if (b == NULL) {
        printf("Memory allocation failed\n");
        fclose(fp);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &b[i]);
    }

    // Sort the array and print intermediate steps
    advancedBubbleSort(b, n, fp);

    // Write the final sorted array and results to the file
    fseek(fp, 0, SEEK_END);
    fprintf(fp, "Fully Sorted Array: ");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", b[i]);
    }
    fprintf(fp, "\n");
    fprintf(fp, "Second Smallest Element: %d\n", b[1]);
    fprintf(fp, "Second Largest Element: %d\n", b[n-2]);
    fclose(fp);

    // Read and print the file contents
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
    free(b);
    return 0;
}
