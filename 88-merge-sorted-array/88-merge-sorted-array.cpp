class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> x(m+n);
        int index1 = 0;
        int index2 = 0;
        int k = 0;
        while(index1<m && index2<n){
            if(nums1[index1] < nums2[index2])
                x[k++] = nums1[index1++];
            else x[k++] = nums2[index2++];
        }
        // while(idx1<m)
        //     x[k++] = nums1[idx1++];
        // while(idx2<n)
        //     x[k++] = nums2[idx2++];
        if(index1 < m){
            for(int i=index1;i<m;i++){
                x[k++] = nums1[i];
            }
        }
        if(index2 < n){
            for(int i=index2;i<n;i++){
                x[k++] = nums2[i];
            }
        }
        nums1 = x;
    }
};