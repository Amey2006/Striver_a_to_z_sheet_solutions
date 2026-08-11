class Solution {
public:
    bool possible(vector<int>& nums, int mid,int threshold) 
    {
        int total_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            total_sum += ceil((double)nums[i] / mid);
        }
        // cout<<total_sum<<" < ="<<threshold<<endl;
        return (total_sum<=threshold);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lower=1;
        int higher=INT_MIN;
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            higher=max(higher,nums[i]);
        }
        
        while(lower<=higher)
        {
            // cout<<"Lower : "<<lower<<endl;
            // cout<<"Higher : "<<higher<<endl;
            int mid=lower+(higher-lower)/2;
            // cout<<"MID : "<<mid<<endl;
            if(possible(nums,mid,threshold))
            {
                // cout<<"Possible with : "<<mid<<endl;
                ans=mid;
                higher=mid-1;
            }
            else
            {
                lower=mid+1;
            }
        }
        return ans;
    }
};