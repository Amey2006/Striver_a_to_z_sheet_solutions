class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        
        unordered_map<int, int> dp;
        int max_len = 0;
        
        for (int num : nums) {
            
            dp[num + 1] = dp[num] + 1;
            dp[num] = dp[num - 1] + 1;
            max_len = max({max_len, dp[num], dp[num + 1]});
        }
        
        return max_len;
    }
};