#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int item_id;
    float item_profit;
    float item_weight;
    float profit_weight_ratio;
} ITEM;

void swap(ITEM *x, ITEM *y) {
    ITEM temp = *x;
    *x = *y;
    *y = temp;
}

void max_heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void build_max_heap(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        max_heapify(arr, n, i);
    }
}

void heap_sort(ITEM arr[], int n) {
    build_max_heap(arr, n);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }
}

float fractional_knapsack(ITEM items[], int n, float capacity) {
    heap_sort(items, n);

    float total_profit = 0.0;

    for (int i = n - 1; i >= 0; i--) {
        if (capacity == 0) {
            break;
        }
        float amount = (items[i].item_weight <= capacity) ? 1.0 : capacity / items[i].item_weight;
        total_profit += amount * items[i].item_profit;
        capacity -= amount * items[i].item_weight;

        printf("Item No: %d profit: %.6f weight: %.6f amount to be taken: %.6f\n", 
                items[i].item_id, items[i].item_profit, items[i].item_weight, amount);
    }

    return total_profit;
}

int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    ITEM items[n];

    for (int i = 0; i < n; i++) {
        items[i].item_id = i + 1;
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    float max_profit = fractional_knapsack(items, n, capacity);
    printf("Maximum profit: %.6f\n", max_profit);

    return 0;
}
