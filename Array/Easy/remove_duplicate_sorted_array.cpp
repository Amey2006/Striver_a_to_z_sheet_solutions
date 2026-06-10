#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates( vector<int>& nums) {
        // Edge case: An empty array has 0 unique elements
        if (nums.empty()) return 0;
        
        // 'insertIndex' keeps track of the position for the next unique element
        int insertIndex = 1; 
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current element is different from the previous one, it's unique
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i];
                insertIndex++; // Move the pointer forward
            }
        }
        
        // 'insertIndex' represents the total number of unique elements
        return insertIndex;
    }
};

int main() {
    Solution sol;
   vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    
    int k = sol.removeDuplicates(nums);
    
   cout << "Number of unique elements: " << k << "\n";
   cout << "The modified array: ";
    for (int i = 0; i < k; i++) {
       cout << nums[i] << " ";
    }
   cout << "\n";
    
    return 0;
}