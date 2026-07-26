class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1=m-1;
        int n2=nums2.size()-1;
        int last=m+n-1;
        while(n1>=0 && n2>=0)
        {
            if(nums1[n1]>nums2[n2])
            {
                nums1[last--]=nums1[n1--];
            }else 
            if(nums1[n1]<=nums2[n2])
            {
                nums1[last--]=nums2[n2--];
            }
        }
         while(n2>=0)
        {
            nums1[last--]=nums2[n2--];
        }
        
    }
};