/*Aim of the program: Write a menu driven program to sort a list of elements in ascending
order using Insertion Sort technique. The nature of the input data is choice based and a distinct
file is considered for each choice. The sorted elements can be stored in a separate output file.
After sorting display the content of the output file along with number of comparisons. Based on
the number of comparisons, conclude the input scenario is either best or worst case.
Note#
● Number of elements in each input file should vary from 300 to 500 entries.
● For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40 .....,
Store the result in “outInsAsce.dat”.
● For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60....,
Store the result in “outInsDesc.dat”.
● For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 ...,
Store the result in “outInsRand.dat”
*/
#include <stdio.h>
#include <stdlib.h>

// Function to perform insertion sort and count comparisons
void sort(int arr[], int n, int *c) {
*c = 0;
for (int i = 1; i < n; i++) {
int key = arr[i];
int j = i - 1;
 while (j >= 0 && arr[j] > key) {
(*c)++;
arr[j + 1] = arr[j];
j--;
}
arr[j + 1] = key;
if (j >= 0) { // Last comparison when the while loop fails
(*c)++;
 }
}
}

// Function to read data from a file
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

// Function to write data to a file
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

// Function to display the content of a file
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
    int n, comparisons;
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

        // Sort the data and count comparisons
        sort(arr, n, &comparisons);

        // Write sorted data to output file
        write(output_file, arr, n);

        // Display the sorted data
        printf("\nSorted Data:\n");
        display(output_file);

        // Display the number of comparisons
        printf("\nNumber of comparisons: %d\n", comparisons);

        // Determine if best or worst case
        if (choice == 1) {
            int expected_comparisons = n - 1;
            if (comparisons == expected_comparisons) {
                printf("Scenario: Best Case\n");
            } else {
                printf("Scenario: Worst Case\n");
            }
        } else if (choice == 2) {
            int expected_comparisons = (n * (n - 1)) / 2;
            if (comparisons == expected_comparisons) {
                printf("Scenario: Best Case\n");
            } else {
                printf("Scenario: Worst Case\n");
            }
        } else {
            printf("Scenario: Random Case\n");
        }
    }

    return 0;
}
