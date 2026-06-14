#include <iostream>
#include <vector>
using namespace std;
void moveZeroes(vector<int>& nums) {
    int insertPos = 0;
    
    for (int i = 0; i < nums.size(); i++) {
        // If the current element is non-zero, swap it
        if (nums[i] != 0) {
            swap(nums[insertPos], nums[i]);
            insertPos++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    
    moveZeroes(nums);
    
    // Output the result
    for (int num : nums) {
        cout << num << " ";
    }
    // Output: 1 3 12 0 0
    
    return 0;
}