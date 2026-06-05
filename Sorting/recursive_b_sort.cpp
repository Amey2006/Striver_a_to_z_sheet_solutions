#include <iostream>
#include <vector>
using namespace std;
// Recursive function to sort the array
void recursiveBubbleSort(std::vector<int>& arr, int n) {
    // Base case: If the array size is 1, it's already sorted
    if (n == 1) {
        return;
    }

    bool swapped = false;

    // One pass of bubble sort. After this loop, the largest 
    // element in the current subarray is moved to the end.
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
           swap(arr[i], arr[i + 1]);
            swapped = true;
        }
    }

    // Optimization: If no elements were swapped in this pass, 
    // then the array is already sorted.
    if (!swapped) {
        return;
    }

    // Recursive call for the remaining n-1 elements
    recursiveBubbleSort(arr, n - 1);
}

// Helper function to print the array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> data = {64, 34, 25, 12, 22, 11, 90};
    
    cout << "Original array: ";
    printArray(data);

    recursiveBubbleSort(data, data.size());

    cout << "Sorted array:   ";
    printArray(data);

    return 0;
}