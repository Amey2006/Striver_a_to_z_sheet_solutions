class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left=0;
        int right=arr.size()-1;
        int missing;
        while(left<=right)
        {
            int mid=left+(right- left)/2;
            missing=(arr[mid]-1)-mid;
            // cout<<"missing : "<<missing<<endl;
            if(missing<k)
            {
                left=mid+1;
            }
            else right=mid-1;
        }
        // cout<<"Right = "<<right<<endl;
        // cout<<"Left = "<<left<<endl;
        return left+k;
    }
};