#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
class Solution {
public:
    bool in_time(vector<int>& piles,int k,int &h)
    {
        int hours=0;
        for(int i=0;i<piles.size();i++)
        {
            hours += (piles[i] + k - 1) / k;
            if(hours>h)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=INT_MIN;
        int ans=INT_MAX;
        for(int i:piles)
        {
            right=max(i,right);
        }
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(in_time(piles,mid,h))
            {
                ans=mid;
                right=mid-1;
            }else
            {
                left=mid+1;
            }

        }
        return ans;
    }
};