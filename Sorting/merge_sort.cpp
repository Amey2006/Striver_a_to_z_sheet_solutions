#include <iostream>
#include <vector>
using namespace std;
// This function merges two sorted sub-arrays into a single sorted section.
// First sub-array is arr[left..mid]
// Second sub-array is arr[mid+1..right]
void merge( vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of the left sub-array
    int n2 = right - mid;    // Size of the right sub-array

    // Create temporary vectors to hold the data
     vector<int> left_arr(n1);
     vector<int> right_arr(n2);

    // Copy data to temporary vectors
    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[mid + 1 + j];

    // Merge the temporary vectors back into the original arr[left..right]
    int i = 0;    // Initial index of first sub-array
    int j = 0;    // Initial index of second sub-array
    int k = left; // Initial index of merged sub-array

    while (i < n1 && j < n2) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of left_arr[], if there are any
    while (i < n1) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of right_arr[], if there are any
    while (j < n2) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// The main merge_sort function that recursively splits and sorts the array
void merge_sort( vector<int>& arr, int left, int right) {
    // Base case: If left index meets or passes right index, the segment is sorted
    if (left >= right) {
        return;
    }

    // Same as (left + right) / 2, but prevents overflow for large indices
    int mid = left + (right - left) / 2;

    // --- 1. DIVIDE & CONQUER ---
    merge_sort(arr, left, mid);      // Sort the left half
    merge_sort(arr, mid + 1, right);  // Sort the right half

    // --- 2. COMBINE ---
    merge(arr, left, mid, right);    // Merge the two sorted halves
}

// Helper function to print the vector
void print_vector(const  vector<int>& arr) {
    for (int num : arr) {
         cout << num << " ";
    }
     cout <<  endl;
}

int main() {
     vector<int> test_array = {38, 27, 43, 3, 9, 82, 10};

     cout << "Original array: ";
    print_vector(test_array);

    // Pass the array, starting index (0), and ending index (size - 1)
    merge_sort(test_array, 0, test_array.size() - 1);

    cout << "Sorted array:   ";
    print_vector(test_array);

    return 0;
}