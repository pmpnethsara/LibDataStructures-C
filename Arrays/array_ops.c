#include <stdio.h>
#include "array_ops.h"





// Task 3.1: Traverse
// Prints all active elements in the array alongside their indices.
void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        printf("Index %d: %d\n", i, arr[i]);
    }
}

// Task 3.2: Linear Search
// Searches for target; returns index of first occurrence, or -1 if not found.
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Task 3.3: Update by Value
// Replaces first occurrence of oldValue with newValue.
// Returns 1 on success, 0 if oldValue is not found.
int updateByValue(int arr[], int size, int oldValue, int newValue) {
    int index = linearSearch(arr, size, oldValue);
    if (index != -1) {
        arr[index] = newValue;
        return 1;
    }
    printf("Element %d not found.\n", oldValue);
    return 0;
}

// Task 4.1: Insert at Any Position
// Inserts value at the given index, shifting elements right.
void insertAt(int arr[], int *size, int capacity, int position, int value) {
    if (*size >= capacity) {
        printf("Overflow: Array is full.\n");
        return;
    }
    if (position < 0 || position > *size) {
        printf("Invalid position for insertion.\n");
        return;
    }
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*size)++;
}

// Task 5.1: Delete from Any Position
// Removes element at position, shifting remaining elements left.
void deleteAt(int arr[], int *size, int position) {
    if (*size <= 0) {
        printf("Underflow: Array is empty.\n");
        return;
    }
    if (position < 0 || position >= *size) {
        printf("Invalid position for deletion.\n");
        return;
    }
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

// Task 6: Search All Occurrences
// Prints all indices where target appears.
void searchAll(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Found target %d at index: %d\n", target, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Target %d not found in the array.\n", target);
    }
}


int main() {
    // Initialize array with static capacity and tracked size
    int arr[CAPACITY] = {10, 20, 30, 40, 30};
    int size = 5;

    printf("--- 1. Initial Array Traversal ---\n");
    traverse(arr, size);

    printf("\n--- 2. Linear Search ---\n");
    int index = linearSearch(arr, size, 30);
    printf("First occurrence of 30 is at index: %d\n", index);

    printf("\n--- 3. Search All Occurrences ---\n");
    printf("Searching for all occurrences of 30:\n");
    searchAll(arr, size, 30);

    printf("\n--- 4. Update by Value ---\n");
    if (updateByValue(arr, size, 20, 25)) {
        printf("Updated 20 to 25 successfully.\n");
    }
    traverse(arr, size);

    printf("\n--- 5. Insertion ---\n");
    // Insert value 15 at index 1
    insertAt(arr, &size, CAPACITY, 1, 15);
    printf("Array after inserting 15 at index 1:\n");
    traverse(arr, size);

    printf("\n--- 6. Deletion ---\n");
    // Delete element at index 3
    deleteAt(arr, &size, 3);
    printf("Array after deleting element at index 3:\n");
    traverse(arr, size);

    return 0;
}