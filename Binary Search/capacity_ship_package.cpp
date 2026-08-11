class Solution {
public:
    bool possible(vector<int>& weights, int mid, int days)
{
    int required_days = 1;
    int current_weight = 0;

    for(int i = 0; i < weights.size(); i++)
    {
        if(current_weight + weights[i] > mid)
        {
            required_days++;
            current_weight = 0;
        }

        current_weight += weights[i];
    }

    return required_days <= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int minimum = *max_element(weights.begin(), weights.end());
        int maximum=0;
        int ans;
        for(int i=0;i<weights.size();i++)
        {
            maximum+=weights[i];
        }
        while(minimum<=maximum)
        {
            int mid=minimum+(maximum-minimum)/2;
            if(possible(weights,mid,days))
            {
                ans=mid;
                maximum=mid-1;  
            }
            else minimum=mid+1;
        }
        return ans;
    }
};