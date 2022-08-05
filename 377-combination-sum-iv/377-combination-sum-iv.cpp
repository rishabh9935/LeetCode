class Solution {
public:
    int cs(vector<int>& nums, int target, vector<int> &dp){
        if(target < 0) return 0;
        if(target == 0) return 1;
        
        if(dp[target] != -1){
            return dp[target];
        }
        
        int count = 0;
        for(int i=0;i<nums.size();i++){
            count += cs(nums, target-nums[i], dp);
        }
        return dp[target] = count;
        
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        cs(nums, target, dp);
        return dp[target];
    }
};