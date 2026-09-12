class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
        int lefteven=0;
        int leftodd=0;
        int totaleven=0;
        int totalodd=0;

        for(int i=0;i<n;i+=2)
        {
            totaleven+=nums[i];
        }
        for(int i=1;i<n;i+=2)
        {
            totalodd+=nums[i];
        }

        for(int i=0;i<n;i++)
        {
            bool iseven=i%2==0;

            if(iseven){
                totaleven-=nums[i];
            }
            else{
                totalodd-=nums[i];
            }

            int new_totaleven=lefteven+totalodd;
            int new_totalodd=leftodd+totaleven;

            if(new_totaleven==new_totalodd)  ans++ ;
        
                if (iseven)lefteven+=nums[i];
                else leftodd+=nums[i];

        }
        return ans;
    }
};