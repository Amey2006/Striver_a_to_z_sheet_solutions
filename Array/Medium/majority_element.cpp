class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int ans_count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ans_count==0)
            {
                ans=nums[i];
                ans_count++;
            }
            else if(nums[i]!=ans)ans_count--;
            else if(nums[i]==ans)ans_count++;
        }
        return ans;
    }
};