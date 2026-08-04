#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
      
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target)right=mid-1;
            else left=mid+1;
        }
        return right+1;;
    }
};

int main() {
    Solution solution;

    // Test Case 1: Target exists in the array
    std::vector<int> nums1 = {1, 3, 5, 6};
    int target1 = 5;
    std::cout << "Test 1 Expected: 2 | Actual: " << solution.searchInsert(nums1, target1) << std::endl;

    // Test Case 2: Target does not exist (insert in middle)
    std::vector<int> nums2 = {1, 3, 5, 6};
    int target2 = 2;
    std::cout << "Test 2 Expected: 1 | Actual: " << solution.searchInsert(nums2, target2) << std::endl;

    // Test Case 3: Target does not exist (insert at end)
    std::vector<int> nums3 = {1, 3, 5, 6};
    int target3 = 7;
    std::cout << "Test 3 Expected: 4 | Actual: " << solution.searchInsert(nums3, target3) << std::endl;

    return 0;
}