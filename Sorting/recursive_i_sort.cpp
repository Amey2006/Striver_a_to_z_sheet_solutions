#include <iostream>
using name  std;
// Recursive function to sort an array using insertion sort
void recursiveInsertionSort(int arr[], int n) {
    // Base case: If the array has 1 or 0 elements, it is already sorted
    if (n <= 1) {
        return;
    }

    // Step 1: Recursively sort the first n-1 elements
    recursiveInsertionSort(arr, n - 1);

    // Step 2: Insert the last element into its correct position in the sorted subarray
    int lastElement = arr[n - 1];
    int j = n - 2;

    /* Move elements of arr[0..n-2] that are greater than the lastElement
       to one position ahead of their current position */
    while (j >= 0 && arr[j] > lastElement) {
        arr[j + 1] = arr[j];
        j--;
    }
    
    // Place the last element in its correct spot
    arr[j + 1] = lastElement;
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    recursiveInsertionSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}