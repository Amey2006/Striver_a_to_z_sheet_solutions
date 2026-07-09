class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left=nums.size()-1;
        int p=nums.size()-1;
        while(left>0 && nums[left-1]>=nums[left])left--;
        if(left==0)
        {
            reverse(nums.begin(),nums.end());
        }
        else

       {
        while(nums[p]<=nums[left-1])p--;
         swap(nums[left-1],nums[p]);
        reverse(nums.begin()+left,nums.end());}
    }
};