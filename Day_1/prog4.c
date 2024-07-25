#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <number of integers> <input file> <output file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);//array to integer
    char *inputFileName = argv[2];
    char *outputFileName = argv[3];
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file %s.\n", inputFileName);
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file %s.\n", outputFileName);
        fclose(inputFile);
        return 1;
    }
        if (n < 30) {
        printf("Array should have at least thirty elements\n");
        fclose(inputFile);
        return 1;
    }

    int b;
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &b) != 1) {
            printf("Error reading number from input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
        fprintf(outputFile, "%d\n", b);
    }

    fclose(inputFile);
    fclose(outputFile);

    // Print the content of the output file to the console
    outputFile = fopen(outputFileName, "r");
    if (outputFile == NULL) {
        printf("Error opening output file %s for reading.\n", outputFileName);
        return 1;
    }
    char ch;
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }
    fclose(outputFile);

    return 0;
}
