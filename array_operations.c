#include <stdio.h>
#include <stdlib.h>

// Function to print the array
void printArray(int arr[], int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

// Function to insert a value at a specific index
int insertElement(int arr[], int *size, int capacity, int element, int index) {
    if (*size >= capacity) {
        printf("Error: Array capacity exceeded!\n");
        return 0;
    }
    if (index < 0 || index > *size) {
        printf("Error: Invalid index for insertion!\n");
        return 0;
    }

    // Shift elements to the right to make space
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1];
    }

    arr[index] = element;
    (*size)++;
    return 1;
}

// Function to delete a value at a specific index
int deleteElement(int arr[], int *size, int index) {
    if (*size <= 0) {
        printf("Error: Array is already empty!\n");
        return 0;
    }
    if (index < 0 || index >= *size) {
        printf("Error: Invalid index for deletion!\n");
        return 0;
    }

    // Shift elements to the left to fill the gap
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--;
    return 1;
}

int main() {
    int capacity = 100; // Maximum capacity of the array
    int *arr = (int *)malloc(capacity * sizeof(int));
    int size = 0;

    // 1. Creating/Initializing an array of a given size
    printf("--- 1. Initializing Array ---\n");
    size = 5;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    printf("Initial array of size %d: ", size);
    printArray(arr, size);

    // 2. Inserting a value (Inserting 25 at index 2)
    printf("\n--- 2. Inserting Value ---\n");
    printf("Inserting 25 at index 2...\n");
    insertElement(arr, &size, capacity, 25, 2);
    printf("Array after insertion: ");
    printArray(arr, size);

    // 3. Deleting a value (Deleting the element at index 4, which is 40)
    printf("\n--- 3. Deleting Value ---\n");
    printf("Deleting element at index 4...\n");
    deleteElement(arr, &size, 4);
    printf("Array after deletion: ");
    printArray(arr, size);

    // Free allocated memory
    free(arr);
    return 0;
}
