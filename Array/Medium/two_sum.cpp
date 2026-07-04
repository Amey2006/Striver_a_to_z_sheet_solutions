#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: Key = Number, Value = Index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement is found, return its index and the current index
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Otherwise, insert the current number and its index into the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found (though a solution is guaranteed)
        return {};
    }
};

int main() {
    Solution solver;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solver.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: [" << result[0] << ", " << result[1] << "]\n"; // Output: [0, 1]
    } else {
        cout << "No solution found.\n";
    }
    
    return 0;
}