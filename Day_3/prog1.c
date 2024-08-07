#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to merge two sorted arrays
void merge(int arr[], int left, int mid, int right, int *comparisons) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++; // Count each comparison
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right, int *comparisons) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons);
        mergeSort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

// Function to read data from file
void readDataFromFile(char *filename, int arr[], int *size) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    int i = 0;
    while (fscanf(fp, "%d", &arr[i]) != EOF) {
        i++;
    }

    *size = i;
    fclose(fp);
}

// Function to write data to file
void writeDataToFile(char *filename, int arr[], int size) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);
}

int main() {
    int option;
    char filename[20];
    int arr[500];
    int size;
    int comparisons = 0;
    clock_t start, end;

    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");
    printf("Enter option: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            strcpy(filename, "inAsce.dat");
            readDataFromFile(filename, arr, &size);
            printf("Before Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

            start = clock();
            mergeSort(arr, 0, size - 1, &comparisons);
            end = clock();

            printf("After Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Number of Comparisons: %d\n", comparisons);
            printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

            strcpy(filename, "outMergeAsce.dat");
            writeDataToFile(filename, arr, size);
            break;

        case 2:
            strcpy(filename, "inDesc.dat");
            readDataFromFile(filename, arr, &size);
            printf("Before Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

            start = clock();
            mergeSort(arr, 0, size - 1, &comparisons);
            end = clock();

            printf("After Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Number of Comparisons: %d\n", comparisons);
            printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

            strcpy(filename, "outMergeDesc.dat");
            writeDataToFile(filename, arr, size);
            break;

        case 3:
            strcpy(filename, "inRand.dat");
            readDataFromFile(filename, arr, &size);
            printf("Before Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");

            start = clock();
            mergeSort(arr, 0, size - 1, &comparisons);
            end = clock();

            printf("After Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Number of Comparisons: %d\n", comparisons);
            printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

            strcpy(filename, "outMergeRand.dat");
            writeDataToFile(filename, arr, size);
            break;

        case 4:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid option\n");
    }

    return 0;
}
