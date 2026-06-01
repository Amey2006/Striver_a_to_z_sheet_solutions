/**
 * @file bubble_sort_optimized.cpp
 * @brief Optimized Implementation of Bubble Sort Algorithm in C++
 * * Time Complexity:  O(N^2) Worst/Average Case, O(N) Best Case (Early termination)
 * Space Complexity: O(1)   - In-place sorting algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm> // Required for std::swap

using namespace std;

int main() 
{
    // Initialize an unsorted vector of integers
    vector<int> nums = {45, 6, 34, 12, 67, 4, 40, 7, 35, 22};
    
    cout << "Before Sort:\n";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n\n";
    
    // Flag to optimize the algorithm for nearly/fully sorted arrays
    bool swapped = false;
    
    // BUBBLE SORT LOGIC
    for (int i = 0; i < nums.size(); i++) 
    {
        swapped = false; // Reset the flag for each pass
        
        // (int) cast added to prevent underflow if nums is empty
        for (int j = 0; j < (int)nums.size() - i - 1; j++) 
        {
            // If the current element is greater than the next, swap them
            if (nums[j] > nums[j + 1]) 
            {
                swapped = true;
                swap(nums[j], nums[j + 1]);
            }
        }
        
        // If no two elements were swapped in the inner loop, the array is sorted
        if (!swapped) {
            break;
        }
    }
    
    cout << "After Sort:\n";
    for (int i : nums) {
        cout << i << " ";
    }
    cout << "\n\n";
    
    return 0;
}
