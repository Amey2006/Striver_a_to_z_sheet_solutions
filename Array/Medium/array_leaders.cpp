class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
      int largest=INT_MIN;
      vector<int>answer;
      for(int i=nums.size()-1;i>=0;i--)
      {
        if(nums[i]>largest)
        {
            answer.push_back(nums[i]);
            largest=nums[i];
        }
      }
      reverse(answer.begin(),answer.end());
      return answer;
    }
};