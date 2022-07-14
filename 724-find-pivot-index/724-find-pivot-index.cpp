class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum=0;
        int ans = -1;
        int rsum=0;
        for(int i=1;i<nums.size();i++)
            rsum+=nums[i];
        for(int i=0;i<nums.size();i++){
            if(lsum==rsum){
                ans = i;
                break;
            }
            lsum+=nums[i];
            if(i<nums.size()-1)
                rsum=rsum-nums[i+1];
        }
        return ans;
    }
};