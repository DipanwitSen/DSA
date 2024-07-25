#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Name-Dipanwita Sen
//Roll=22052204
#define MAX_NUMBERS 1000

int main() {
    FILE *inputFile;
    int *numbers = NULL;
    int num = 0;
    char filename[100];

    // Get filename from user
    printf("Enter the input file name: ");
    scanf("%s", filename);

    inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Invalid input file\n");
        return 1;
    }

    // Allocate initial memory for numbers
    numbers = (int*)malloc(MAX_NUMBERS * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        fclose(inputFile);
        return 1;
    }

    // Read all numbers from the file
    printf("Reading numbers from the file...\n");
    while (fscanf(inputFile, "%d", &numbers[num]) == 1) {
        num++;
        if (num >= MAX_NUMBERS) {
            printf("Reached maximum number of elements\n");
            break;
        }
    }

    fclose(inputFile);

    printf("Total numbers read: %d\n", num);

    // Process the numbers
    int *count = (int*)calloc(100001, sizeof(int));  // Assuming numbers are between 0 and 100000
    if (count == NULL) {
        printf("Memory allocation failed\n");
        free(numbers);
        return 1;
    }

    int repeating_numbers = 0;
    int max_repeat = 0;
    int max_repeat_num = 0;

    for (int i = 0; i < num; i++) {
        count[numbers[i]]++;
        if (count[numbers[i]] == 2) {
            repeating_numbers++;
        }
        if (count[numbers[i]] > max_repeat) {
            max_repeat = count[numbers[i]];
            max_repeat_num = numbers[i];
        }
    }

    printf("Number of repeating numbers: %d\n", repeating_numbers);
    printf("Number with maximum repetitions: %d (repeats %d times)\n", max_repeat_num, max_repeat);

    // Free allocated memory
    free(numbers);
    free(count);

    return 0;
}
