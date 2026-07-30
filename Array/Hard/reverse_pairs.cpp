#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void mergesort(vector<int>& nums,int left,int right,int &count)
    {
        
        if(left<right)
        {
            int mid=left+(right-left)/2;
            mergesort(nums,left,mid,count);
            mergesort(nums,mid+1,right,count);
            merge(nums,left,right,mid,nums.size(),count);
        }
    }
    void merge(vector<int>& nums,int low ,int high, int mid,int n,int &count)
    {   
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && nums[i] > 2LL * nums[j]) {  
                j++;
            }
            count += (j - (mid + 1)); 
        }
        int i=low;
        j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=high)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i]);
                i++;
                            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid)temp.push_back(nums[i++]);
        while(j<=high)temp.push_back(nums[j++]);
        for (int k = low; k <= high; k++) {
        nums[k] = temp[k - low];
         }
    }
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergesort(nums,0,nums.size()-1,count);
        return count;
    }
};

int main() {
    int n;
    cout<<"Enter N : ";
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cout<<"Nums["<<i<<"] = ";
        cin >> nums[i];
        cout<<endl;
    }
    
    Solution obj;
    cout << "Count : "<<obj.reversePairs(nums) << endl<< endl;
    return 0;
}