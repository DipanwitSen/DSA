//Duplicate in a fileS
#include <stdio.h>
#include <stdlib.h>
//Name-Dipanwita Sen
//Roll=22052204

void binary(int b, FILE *outputFile) {
    if (b > 1) {
        binary(b / 2, outputFile);
    }
    fprintf(outputFile, "%d", b % 2);
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <number of integers> <input file> <output file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
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

    int b;
    for (int i = 0; i < n; i++) {
        if (fscanf(inputFile, "%d", &b) != 1) { // Corrected the condition for reading integers
            printf("Error reading number from input file.\n");
            fclose(inputFile);
            fclose(outputFile);
            return 1;
        }
        fprintf(outputFile, "The binary equivalent of %d is ", b);
        binary(b, outputFile);
        fprintf(outputFile, "\n");
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

/*Return Value of 0:

fscanf returns 0 when it encounters input that does not match the specified format.
For example, if the format specifier is %d (for an integer) but the next item in the input file is a non-numeric character or an invalid integer, fscanf will return 0.
In the program, this would indicate that the input file contains data that cannot be interpreted as an integer, as expected.
Return Value of 1:

fscanf returns 1 when it successfully reads and assigns one input item according to the specified format.
In the context of fscanf(inputFile, "%d", &b), a return value of 1 means that it has successfully read one integer from the file and stored it in the variable b.
Return Value of -1 (EOF):

fscanf returns EOF when it reaches the end of the file before successfully reading and assigning any input items.
EOF is typically defined as -1 in stdio.h.
In the program, this would indicate that the file is empty or that all readable data has already been processed.*/
