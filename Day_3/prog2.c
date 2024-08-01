#include <stdio.h>
#include <stdlib.h>
/* Dipanwita Sen
22052204*/
// Swap function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort (ascending order)
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

// Quicksort function for descending order
void quick_descending(int a[], int lb, int ub) {
    if (lb < ub) {
        int pivot = a[lb];
        int start = lb;
        int end = ub;

        while (start < end) {
            while (a[start] >= pivot && start < end) {
                start++;
            }
            while (a[end] < pivot) {
                end--;
            }
            if (start < end) {
                swap(&a[start], &a[end]);
            }
        }
        swap(&a[lb], &a[end]);
        quick_descending(a, lb, end - 1);
        quick_descending(a, end + 1, ub);
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
    printf("Name:Dipanwita Sen\n Sec:40\n Roll :22052204\n");
    const int max_size = 500;
    int arr[max_size];
    int n;
    char input_file[50], output_file[50];
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
        if (choice == 1) {
            quick(arr, 0, n - 1);
        } else if (choice == 2) {
            quick_descending(arr, 0, n - 1);
        } else {
            quick(arr, 0, n - 1);  // or quick_descending, depending on requirements
        }

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
