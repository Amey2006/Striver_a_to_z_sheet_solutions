#include <iostream>
#include <vector>
#include<algorithm>
#include<stdlib.h>
#include<climits>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Minimum lies in the right unsorted portion
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Minimum is at mid or in the left portion
            else {
                right = mid;
            }
        }

        // When left == right, both pointers converge on the minimum element
        return nums[left];
    }
};

// Simple driver code for testing
int main() {
   
    vector<int> nums = {5, 1, 2, 3, 4};

    Solution solver;
    int result = solver.findMin(nums);

    cout << "The minimum element is: " << result << endl;

    return 0;
}