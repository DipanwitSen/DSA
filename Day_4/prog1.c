#include<stdio.h>
#include<stdlib.h>

struct person {
    int id;
    char name[100];  // Fixed-size array for storing the name
    int age;
    int height;
    int weight;
};

void read_data(struct person *a, int n) {
    for(int i = 0; i < n; i++) {
        printf("ID: %d\n", a[i].id);
        printf("Name: %s\n", a[i].name);
        printf("Age: %d\n", a[i].age);
        printf("Height: %d\n", a[i].height);
        printf("Weight: %d\n\n", a[i].weight);
    }
}

// Helper functions to maintain the heap properties
void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(struct person *a, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left].age < a[smallest].age)
        smallest = left;

    if (right < n && a[right].age < a[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&a[i], &a[smallest]);
        min_heapify(a, n, smallest);
    }
}

void max_heapify(struct person *a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left].weight > a[largest].weight)
        largest = left;

    if (right < n && a[right].weight > a[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        max_heapify(a, n, largest);
    }
}

void build_min_heap(struct person *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(a, n, i);
    }
}

void build_max_heap(struct person *a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(a, n, i);
    }
}

void display_weight_of_youngest(struct person *a) {
    printf("Weight of the youngest person: %d\n", a[0].weight);
}

void insert_min_heap(struct person *a, int *n, struct person new_person) {
    a[*n] = new_person;
    (*n)++;
    int i = *n - 1;
    while (i != 0 && a[(i - 1) / 2].age > a[i].age) {
        swap(&a[i], &a[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void delete_oldest(struct person *a, int *n) {
    if (*n == 0) {
        printf("Heap is empty!\n");
        return;
    }
    int oldest_idx = 0;
    for (int i = 1; i < *n; i++) {
        if (a[i].age > a[oldest_idx].age) {
            oldest_idx = i;
        }
    }
    swap(&a[oldest_idx], &a[*n - 1]);
    (*n)--;
    if (oldest_idx < *n) {
        min_heapify(a, *n, oldest_idx);
    }
}

int main() {
    struct person *a;
    int n;
    int choice;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for n persons
    a = (struct person*)malloc(n * sizeof(struct person));

    // Input data for each person
    for(int i = 0; i < n; i++) {
        printf("Enter details for person %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &a[i].id);
        printf("Name: ");
        scanf("%s", a[i].name);
        printf("Age: ");
        scanf("%d", &a[i].age);
        printf("Height: ");
        scanf("%d", &a[i].height);
        printf("Weight: ");
        scanf("%d", &a[i].weight);
    }

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                read_data(a, n);
                break;
            case 2:
                build_min_heap(a, n);
                printf("Min-heap created based on age.\n");
                break;
            case 3:
                build_max_heap(a, n);
                printf("Max-heap created based on weight.\n");
                break;
            case 4:
                display_weight_of_youngest(a);
                break;
            case 5: {
                struct person new_person;
                printf("Enter details for the new person:\n");
                printf("ID: ");
                scanf("%d", &new_person.id);
                printf("Name: ");
                scanf("%s", new_person.name);
                printf("Age: ");
                scanf("%d", &new_person.age);
                printf("Height: ");
                scanf("%d", &new_person.height);
                printf("Weight: ");
                scanf("%d", &new_person.weight);
                insert_min_heap(a, &n, new_person);
                printf("New person inserted into the Min-heap.\n");
                break;
            }
            case 6:
                delete_oldest(a, &n);
                printf("Oldest person deleted.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 7);

    // Free the allocated memory
    free(a);

    return 0;
}
