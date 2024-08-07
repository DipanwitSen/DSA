#include <stdio.h>
#include <stdlib.h>
int findMax(int arr[], int size) {
int max = arr[0];
for (int i = 1; i < size; i++) {
if (arr[i] > max) {
max = arr[i];
}
}
return max;
}

// Function to perform Counting Sort
void countingSort(int arr[], int size) {
int max = findMax(arr, size);
int *count = (int *)calloc((max + 1), sizeof(int));
for (int i = 0; i < size; i++) {
count[arr[i]]++;
}
int index = 0;
for (int i = 0; i <= max; i++) {
while (count[i] > 0) {
arr[index++] = i;
count[i]--;
}
}
free(count);
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
clock_t start, end;
printf("MAIN MENU (COUNTING SORT)\n");
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
  countingSort(arr, size);
  end = clock();
  printf("After Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

            strcpy(filename, "outCountAsce.dat");
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
            countingSort(arr, size);
            end = clock();

            printf("After Sorting: ");
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);

            strcpy(filename, "outCountDesc.dat");
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
    countingSort(arr, size);
    end = clock();
    printf("After Sorting: ");
    for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
     }
    printf("\n");
    printf("Execution Time: %ld microseconds\n", (end - start) * 1000000 / CLOCKS_PER_SEC);
    strcpy(filename, "outCountRand.dat");
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
