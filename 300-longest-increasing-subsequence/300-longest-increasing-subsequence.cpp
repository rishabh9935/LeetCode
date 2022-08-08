class Solution {
public:
    int dp[2500][2501];
    
    int solve(int curr, int prev, vector<int>& nums, int n){
        if(curr == n) return 0;
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
        int len = 0 + solve(curr+1, prev, nums, n);
        if(prev == -1 || nums[prev] < nums[curr])
            len = max(len, 1+solve(curr+1, curr, nums, n));
        return dp[curr][prev+1] = len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        memset(dp, -1, sizeof dp);
        return solve(0, -1, nums, n);
    }
};