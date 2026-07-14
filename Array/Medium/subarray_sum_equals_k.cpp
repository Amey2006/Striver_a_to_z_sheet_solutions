class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int, int> prefix_sums;
        
        prefix_sums[0] = 1;
        
        int current_sum = 0;
        int answer = 0;
        
        for (int num : nums) {
            current_sum += num;
            if (prefix_sums.find(current_sum - k) != prefix_sums.end()) {
                answer += prefix_sums[current_sum - k];
            }
            prefix_sums[current_sum]++;
        }
        
        return answer;
    }
};