class Solution {
public:
    vector<vector<int>> dp;
    int help(int i, vector<int>& nums, vector<int>& multipliers, int s){
        if(i == multipliers.size()) return 0;
        if(dp[i][s] != INT_MIN) return dp[i][s];
        int e = nums.size()-(i-s)-1;
        int op1 = multipliers[i]*nums[s] + help(i+1, nums, multipliers, s+1);
        int op2 = multipliers[i]*nums[e] + help(i+1, nums, multipliers, s);
        return dp[i][s] = max(op1, op2);
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        dp.resize(m + 1, vector<int> (m + 1, INT_MIN));
        return help(0, nums, multipliers, 0);
    }
};