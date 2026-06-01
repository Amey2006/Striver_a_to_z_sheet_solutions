#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  vector<int> nums={45,6,34,12,67,4,40,7,35,22};
  cout<<"Before Sort\n";
  for(int i:nums)cout<<i<<endl;
  cout<<"After Sort\n";
  for(int i=0;i<(int)nums.size()-1;i++)
  {
    int smallest=i;
    for(int j=i+1;j<nums.size();j++)
    {
      if(nums[j]<nums[smallest])smallest=j;
    }
    swap(nums[i],nums[smallest]);
  }
  for(int i:nums)cout<<i<<endl;
  return 0;
}
