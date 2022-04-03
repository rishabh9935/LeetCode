class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() , bp ;
        if(n==1){
            nums[0];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                bp=i;
                break;
            }
        }
        if(bp<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>bp;i--){
                if(nums[i]>nums[bp]){
                    swap(nums[bp],nums[i]);
                    break;
                }
            }
            reverse(nums.begin()+bp+1,nums.end());
        }
    }
};
