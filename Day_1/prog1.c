// normal print
#include<stdio.h>
int main() {
    FILE *inputFile;


    inputFile = fopen("input.txt", "r+");
    if (inputFile == NULL) {
        printf("Invalid input file\n");
        return 1;
    }
    int num;
    for (int i = 0; i < 10; i++) {
        if (fscanf(inputFile, "%d", &num) == 1) {
            printf("%d\n", num); // Print to terminal
            fprintf(inputFile, "%d\n", num); // Print to file
        } else {
            printf("Error reading integer from input file\n");
            break;
        }
    }

    fclose(inputFile);

    return 0;
}
