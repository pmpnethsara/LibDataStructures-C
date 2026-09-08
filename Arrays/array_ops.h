#ifndef ARRAY_OPS_H
#define ARRAY_OPS_H

#define CAPACITY 100

// Core Operations
void traverse(int arr[], int size);
int linearSearch(int arr[], int size, int target);
int updateByValue(int arr[], int size, int oldValue, int newValue);
void insertAt(int arr[], int *size, int capacity, int position, int value);
void deleteAt(int arr[], int *size, int position);
void searchAll(int arr[], int size, int target);

#endif