#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Initialize the unsorted vector
    vector<int> nums = {68, 34, 12, 3, 76, 33, 22, 9, 99, 1};
    
    // Display the initial state of the vector
    cout << "Before sort : ";
    for (int num : nums) {
        cout << " " << num;
    }
    cout << "\n\n";
    
    // Insertion Sort Algorithm
    // Start from the second element (index 1) as a single element is already sorted
    for (size_t i = 1; i < nums.size(); i++) { 
        int cur = nums[i];      // The element currently being positioned
        int prev = i - 1;       // Index of the last element in the sorted sub-array
        
        // Shift elements of the sorted segment that are greater than 'cur'
        // to one position ahead of their current position
        while (prev >= 0 && nums[prev] > cur) {
            nums[prev + 1] = nums[prev];
            prev--;
        }
        
        // Insert 'cur' into its correct sorted position
        nums[prev + 1] = cur;
        
        // Print the array state after each pass to track progress
        cout << "Pass " << i << ": ";
        for (int num : nums) {
            cout << " " << num;
        }
        cout << "\n";
    }
    
    // Display the final sorted vector
    cout << "\nAfter sort  : ";
    for (int num : nums) {
        cout << " " << num;
    }
    cout << "\n";
    
    return 0;
}
