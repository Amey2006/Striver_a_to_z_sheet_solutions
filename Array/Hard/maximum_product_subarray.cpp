#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int leftproduct=1,rightproduct=1;
        int ans=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            leftproduct=leftproduct==0 ? 1 :leftproduct;
            rightproduct=rightproduct==0 ? 1: rightproduct;

            leftproduct*=nums[i];
            rightproduct*=nums[nums.size()-1-i];

            ans=max(ans,max(leftproduct,rightproduct));

        }
        return ans;

    }
};

int main() {
    Solution sol;

    // Test Case 1: Standard case with positive numbers
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Test 1 Input: [2, 3, -2, 4]" << endl;
    cout << "Output: " << sol.maxProduct(nums1) << " | Expected: 6" << endl << endl;

    // Test Case 2: Array with zeros
    vector<int> nums2 = {-2, 0, -1};
    cout << "Test 2 Input: [-2, 0, -1]" << endl;
    cout << "Output: " << sol.maxProduct(nums2) << " | Expected: 0" << endl << endl;

    // Test Case 3: Multiple negative numbers canceling out
    vector<int> nums3 = {-2, 3, -4};
    cout << "Test 3 Input: [-2, 3, -4]" << endl;
    cout << "Output: " << sol.maxProduct(nums3) << " | Expected: 24" << endl << endl;

    // Test Case 4: Single element
    vector<int> nums4 = {-5};
    cout << "Test 4 Input: [-5]" << endl;
    cout << "Output: " << sol.maxProduct(nums4) << " | Expected: -5" << endl << endl;

    return 0;
}