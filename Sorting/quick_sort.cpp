#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

/* This function takes the last element as pivot, places 
   the pivot element at its correct position in the sorted array, 
   and places all smaller elements to the left of the pivot 
   and all greater elements to the right of the pivot.
*/
int partition(vector<int>& arr, int low, int high) {
    // Choosing the last element as the pivot
    int pivot = arr[high]; 
    
    // Index of the smaller element; indicates the right position of pivot found so far
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    
    // Swap the pivot element with the element at (i + 1) 
    // so that the pivot sits right between smaller and larger elements
    swap(arr[i + 1], arr[high]);
    
    // Return the partitioning index
    return (i + 1);
}

/*
   The main function that implements Quick Sort
   arr[] --> Vector to be sorted,
   low   --> Starting index,
   high  --> Ending index
*/
void quickSort(vector<int>& arr, int low, int high) {
    // Base case: If low is less than high, there are elements to sort
    if (low < high) {
        
        // pIndex is the partitioning index, arr[pIndex] is now at the right place
        int pIndex = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pIndex - 1);  // Left subarray
        quickSort(arr, pIndex + 1, high); // Right subarray
    }
}

// Helper function to print the vector
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> data = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int n = data.size();

    cout << "Original array: ";
    printArray(data);

    // Call quickSort on the entire vector
    quickSort(data, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(data);

    return 0;
}
