class Solution {
public:
    int dp[1000000];
    int mini(vector<int> &cost, int pos, vector<int> &dp){
        if(pos == 0) return cost[0];
        if(pos == 1) return cost[1];
        if(dp[pos]!=-1) return dp[pos];
        dp[pos] = min(mini(cost, pos-1, dp), mini(cost, pos-2, dp)) + cost[pos];
        return dp[pos];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(mini(cost, n-1, dp), mini(cost, n-2, dp));
        return ans;
    }
};