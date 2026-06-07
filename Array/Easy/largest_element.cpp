#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int largestElement(std::vector<int>& nums) {
        // Handle edge case: if the vector is empty
        if (nums.empty()) {
            return -1; // Or throw an exception depending on requirements
        }

        int max_element = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > max_element) {
                max_element = nums[i];
            }
        }
        
        return max_element;
    }
};
