#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int max_so_far = INT_MIN;
        int current_max = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            current_max += nums[i];
            
            if (max_so_far < current_max) {
                max_so_far = current_max;
            }
    
            if (current_max < 0) {
                current_max = 0;
            }
        }
        
        return max_so_far;
    }
};