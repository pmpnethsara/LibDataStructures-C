#include <stdio.h>

#define CAPACITY 100

// Core Operations
void traverse(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int updateByValue(int arr[], int size, int oldValue, int newValue);
void insertAt(int arr[], int *size, int capacity, int position, int value);
void deleteAt(int arr[], int *size, int position);
void searchAll(int arr[], int size, int target);




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
void 
searchAll(int arr[], int size, int target) {
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
    int marks[CAPACITY];
    int size = 0;
    int choice, pos, val;

    while (1) {
        printf("\n--- Student Marks Manager ---\n");
        printf("1. Add a mark at position\n");
        printf("2. Delete a mark at position\n");
        printf("3. Search for a mark (all occurrences)\n");
        printf("4. Update a mark by index\n");
        printf("5. Display all marks\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter position (0 to %d) and mark: ", size);
                scanf("%d %d", &pos, &val);
                insertAt(marks, &size, CAPACITY, pos, val);
                break;
            case 2:
                printf("Enter position to delete (0 to %d): ", size - 1);
                scanf("%d", &pos);
                deleteAt(marks, &size, pos);
                break;
            case 3:
                printf("Enter mark to search: ");
                scanf("%d", &val);
                searchAll(marks, size, val);
                break;
            case 4:
                printf("Enter index to update (0 to %d): ", size - 1);
                scanf("%d", &pos);
                if (pos >= 0 && pos < size) {
                    printf("Enter new mark: ");
                    scanf("%d", &val);
                    marks[pos] = val;
                    printf("Mark updated successfully.\n");
                } else {
                    printf("Invalid index.\n");
                }
                break;
            case 5:
                traverse(marks, size);
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}