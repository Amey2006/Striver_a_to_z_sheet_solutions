class Solution {
public:
    bool isSorted(vector<int>& nums) {
        int n = nums.size();
        
        // An empty array or an array with 1 element is always sorted
        if (n <= 1) return true;
        
        for (int i = 0; i < n - 1; i++) {
            // If a current element is greater than the next, it's not sorted
            if (nums[i] > nums[i + 1]) {
                return false;
            }
        }
        
        return true;
    }
};
