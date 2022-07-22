class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> x(m+n);
        int idx1 = 0;
        int idx2 = 0;
        int k = 0;
        while(idx1<m && idx2<n){
            if(nums1[idx1] < nums2[idx2])
                x[k++] = nums1[idx1++];
            else x[k++] = nums2[idx2++];
        }
        while(idx1<m)
            x[k++] = nums1[idx1++];
        while(idx2<n)
            x[k++] = nums2[idx2++];
        nums1 = x;
    }
};