#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
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

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int read(const char *file_name, int arr[], int max_size) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return 0;
    }
    int count = 0;
    while (count < max_size && fscanf(file, "%d", &arr[count]) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

void write(const char *file_name, int arr[], int n) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

void display(const char *file_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        return;
    }
    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        printf("%d ", value);
    }
    printf("\n");
    fclose(file);
}

int main() {
    const int max_size = 500;
    int arr[max_size];
    int n;
    char input_file[20], output_file[20];
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Sort Ascending Order Data\n");
        printf("2. Sort Descending Order Data\n");
        printf("3. Sort Random Data\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1:
                snprintf(input_file, sizeof(input_file), "inAsce.dat");
                snprintf(output_file, sizeof(output_file), "outInsAsce.dat");
                break;
            case 2:
                snprintf(input_file, sizeof(input_file), "inDesc.dat");
                snprintf(output_file, sizeof(output_file), "outInsDesc.dat");
                break;
            case 3:
                snprintf(input_file, sizeof(input_file), "inRand.dat");
                snprintf(output_file, sizeof(output_file), "outInsRand.dat");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                continue;
        }

        // Read data from input file
        n = read(input_file, arr, max_size);

        // Sort the data
        quick_sort(arr, 0, n - 1);

        // Write sorted data to output file
        write(output_file, arr, n);

        // Display the sorted data
        printf("\nSorted Data:\n");
        display(output_file);

        // Display the sorting scenario
        if (choice == 1) {
            printf("Scenario: Best Case\n");
        } else if (choice == 2) {
            printf("Scenario: Worst Case\n");
        } else {
            printf("Scenario: Random Case\n");
        }
    }

    return 0;
}
