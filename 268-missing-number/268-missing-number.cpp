class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int ans=0;
        vector<int> nums2;
        sort(nums.begin(),nums.end());
        for(int i=0;i<=size;i++)
            nums2.push_back(i);
        for(int i=0;i<size;i++){
            if(i==size-1)
                ans = nums2[size];
            if(nums[i]!=nums2[i]){
                ans=nums2[i];
                break;
            }
        }
        return ans;
    }
};