#include <iostream>
#include <vector>
#include<algorithm>
#include<stdlib.h>
#include<climits>
using namespace std;
class Solution {
public:
    int findRot(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            else {
                right = mid;
            }
        }

        return left; 
    }
};

// Simple driver code for testing
int main() {
   
    vector<int> nums = {5, 1, 2, 3, 4};

    Solution solver;
    int result = solver.findRot(nums);

    cout << "The rotation is: " << result << endl;

    return 0;
}