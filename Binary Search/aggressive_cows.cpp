#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
using namespace std;
class Solution {
	public:
	bool is_possible(vector<int> &arr, int k,int mid){
	    int cows=1;
	    int lastpos=arr[0];
	    
	    for(int i=1;i<arr.size();i++)
	    {
	        if(arr[i]-lastpos>=mid)
	        {
	            cows++;
	            lastpos=arr[i];
	        }
	        if(cows==k)return true;
	    }
	    return false;
	}
	int aggressiveCows(vector<int> &arr, int k) {
	    sort(arr.begin(),arr.end());
		int right = *max_element(arr.begin(), arr.end());
		int left = 0;
		int ans;
		while (left <= right)
			{
			int mid = left + (right - left)/2;
			if (is_possible(arr,k,mid)) {
				ans = mid;
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		return ans;
	}
};
