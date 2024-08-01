#include <stdio.h>
#include <stdlib.h>
/* Name -Dipanwita sen
   Roll-22052204
   Sec -40 */
// Function to calculate GCD using recursion
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];

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

    int numPairs = 0;
    int a, b;
    while (fscanf(inputFile, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(outputFile, "The GCD of %d and %d is %d\n", a, b, result);
        numPairs++;
    }

    if (numPairs < 20) {
        printf("The input file must contain at least 20 pairs of numbers.\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
