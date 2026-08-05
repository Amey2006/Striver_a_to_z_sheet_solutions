#include <iostream>
#include <vector>
#include <utility>
#include<stdlib.h>
#include<algorithm>
// #include<stdio.h>
#include<climits>
class Solution {
public:
    // Floor: Largest element in nums <= x (return -1 if no such element exists)
    // Ceil:  Smallest element in nums >= x (return -1 if no such element exists)
    std::pair<int, int> getFloorAndCeil(std::vector<int>& nums, int x) {
   int floor = -1;
    int ceil = -1;
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == x) {
            return {x, x};
        } else if (nums[mid] < x) {
            floor = nums[mid]; // Best floor candidate so far
            left = mid + 1;
        } else {
            ceil = nums[mid];  // Best ceil candidate so far
            right = mid - 1;
        }
    }

    return {floor, ceil};}
};

int main() {
    Solution solution;

    // Test Case 1: Standard case where x is between elements
    std::vector<int> nums1 = {3, 4, 4, 7, 8, 10};
    int x1 = 5;
    auto [floor1, ceil1] = solution.getFloorAndCeil(nums1, x1);
    std::cout << "Test 1 | Target: 5  | Expected Floor: 4, Ceil: 7  | Actual Floor: " << floor1 << ", Ceil: " << ceil1 << std::endl;

    // Test Case 2: x exists in the array (Floor and Ceil are equal to x)
    std::vector<int> nums2 = {3, 4, 4, 7, 8, 10};
    int x2 = 7;
    auto [floor2, ceil2] = solution.getFloorAndCeil(nums2, x2);
    std::cout << "Test 2 | Target: 7  | Expected Floor: 7, Ceil: 7  | Actual Floor: " << floor2 << ", Ceil: " << ceil2 << std::endl;

    // Test Case 3: x is smaller than all elements (No Floor exists)
    std::vector<int> nums3 = {3, 4, 4, 7, 8, 10};
    int x3 = 2;
    auto [floor3, ceil3] = solution.getFloorAndCeil(nums3, x3);
    std::cout << "Test 3 | Target: 2  | Expected Floor: -1, Ceil: 3 | Actual Floor: " << floor3 << ", Ceil: " << ceil3 << std::endl;

    // Test Case 4: x is larger than all elements (No Ceil exists)
    std::vector<int> nums4 = {3, 4, 4, 7, 8, 10};
    int x4 = 11;
    auto [floor4, ceil4] = solution.getFloorAndCeil(nums4, x4);
    std::cout << "Test 4 | Target: 11 | Expected Floor: 10, Ceil: -1| Actual Floor: " << floor4 << ", Ceil: " << ceil4 << std::endl;

    return 0;
}