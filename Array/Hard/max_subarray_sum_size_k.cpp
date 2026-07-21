class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
         long long maxsum = 0;
        long long cursum = 0;
        int left = 0;
        int n = nums.size();
        
        unordered_map<int, int> frequencyMap;

        for (int right = 0; right < n; ++right) {
            cursum += nums[right];
            frequencyMap[nums[right]]++;
            if (right - left + 1 > k) {
                cursum -= nums[left];
                frequencyMap[nums[left]]--;
                
                if (frequencyMap[nums[left]] == 0) {
                    frequencyMap.erase(nums[left]);
                }
                left++;
            }

            if (right - left + 1 == k && frequencyMap.size() == k) {
                maxsum = max(maxsum, cursum);
            }
        }
        
        return maxsum;
    }
};