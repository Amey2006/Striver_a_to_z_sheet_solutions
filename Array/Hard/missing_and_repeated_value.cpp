#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        unordered_map<int,int>freq;
        vector<int>ans;
        int total=0;
        int n=nums.size();
        for(int i:nums)
        {
            freq[i]++;
            if(freq[i]<=1)
            total+=i;
            else {ans.push_back(i);
            cout<<i<<" is Repeated..."<<endl;}
        }
        cout<<"Total : "<<total<<endl;
        cout<<"Expected : "<<(n*(n+1))/2<<endl;
        int diff=abs((n*(n+1))/2-total);
        cout<<"Diff : "<<diff<<endl;
        ans.push_back(diff);
        return ans;
    }
};
int main()
{
    Solution s1;
    vector<int>nums={3, 5, 4, 1, 1};
    vector<int>ans=s1.findMissingRepeatingNumbers(nums);
    for(int i:ans)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
    return 0;
}