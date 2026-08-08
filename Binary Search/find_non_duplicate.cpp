class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // Ensure mid is even to always compare mid with mid + 1
            if (mid % 2 == 1) {
                mid--;
            }

            // If mid and mid + 1 are equal, single element is on the right
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                // Otherwise, the single element is at mid or to its left
                right = mid;
            }
        }

        return nums[left];
    }
};