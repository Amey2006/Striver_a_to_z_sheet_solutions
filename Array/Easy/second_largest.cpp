#include <iostream>
#include <vector>
#include <climits> 
using namespace std;
class Solution {
public:
    int findSecondLargest(const vector<int>& arr) {
        // If the array has fewer than 2 elements, a second largest cannot exist
        if (arr.size() < 2) {
            return -1; 
        }

        // Initialize largest and second largest to the smallest possible integer
        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int num : arr) {
            // Case 1: Current element is greater than the current 'largest'
            if (num > largest) {
                // The old largest now becomes the second largest
                secondLargest = largest;
                // Update the largest to the new higher value
                largest = num;
            }
            // Case 2: Current element is smaller than 'largest' but greater than 'secondLargest'
            // We also ensure it's not a duplicate of 'largest'
            else if (num > secondLargest && num != largest) {
                secondLargest = num;
            }
        }

        // If secondLargest was never updated, it means no valid second largest exists 
        // (e.g., all elements in the array were identical, like [10, 10, 10])
        if (secondLargest == INT_MIN) {
            return -1;
        }

        return secondLargest;
    }
};

// Example usage
int main() {
    Solution solver;
    vector<int> nums = {12, 35, 1, 10, 34, 1};
    
    int result = solver.findSecondLargest(nums);
    cout << "The second largest element is: " << result << endl; // Output: 34

    return 0;
}