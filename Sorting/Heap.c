#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct person
typedef struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
} Person;

// Function to read data from file
void readDataFromFile(Person **arr, int *n) {
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        Person *p = (Person *)malloc(sizeof(Person));
        p->name = (char *)malloc(strlen(line) + 1);
        sscanf(line, "%d %s %d %d %d", &p->id, p->name, &p->age, &p->height, &p->weight);
        arr[i] = p;
        i++;
    }

    *n = i;
    fclose(fp);
}

// Function to create a min-heap based on age
void createMinHeap(Person **arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

// Function to create a max-heap based on weight
void createMaxHeap(Person **arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

// Function to heapify the min-heap
void heapifyMin(Person **arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->age < arr[smallest]->age) {
        smallest = left;
    }

    if (right < n && arr[right]->age < arr[smallest]->age) {
        smallest = right;
    }

    if (smallest != i) {
        Person *temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        heapifyMin(arr, n, smallest);
    }
}

// Function to heapify the max-heap
void heapifyMax(Person **arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left]->weight > arr[largest]->weight) {
        largest = left;
    }

    if (right < n && arr[right]->weight > arr[largest]->weight) {
        largest = right;
    }

    if (largest != i) {
        Person *temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapifyMax(arr, n, largest);
    }
}

// Function to display the weight of the youngest person
void displayWeightOfYoungest(Person **arr, int n) {
    printf("Weight of youngest student: %.2f kg\n", (float)arr[0]->weight / 2.20462);
}

// Function to insert a new person into the min-heap
void insertIntoMinHeap(Person **arr, int *n) {
    Person *p = (Person *)malloc(sizeof(Person));
    p->name = (char *)malloc(100);
    printf("Enter id, name, age, height, weight: ");
    scanf("%d %s %d %d %d", &p->id, p->name, &p->age, &p->height, &p->weight);

    arr[*n] = p;
    (*n)++;

    for (int i = *n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, *n, i);
    }
}

// Function to delete the oldest person
void deleteOldest(Person **arr, int *n) {
    Person *temp = arr[0];
    arr[0] = arr[*n - 1];
    arr[*n - 1] = temp;
    (*n)--;

    for (int i = *n / 2 - 1; i >= 0; i--) {
        heapifyMin(arr, *n, i);
    }
}

int main() {
    Person **arr = (Person **)malloc(100 * sizeof(Person *));
    int n = 0;

    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2
