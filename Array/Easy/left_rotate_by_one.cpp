#include <iostream>
#include <vector>

using namespace std;

void leftRotateByOne(vector<int>& arr) {
    // Handle edge case of an empty array or single element
    if (arr.size() <= 1) {
        return;
    }
    
    int n = arr.size();
    int temp = arr[0]; // Store the first element
    
    // Shift the rest of the elements to the left
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    // Put the first element at the end
    arr[n - 1] = temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    
    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    leftRotateByOne(arr);
    
    cout << "Rotated array:  ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}