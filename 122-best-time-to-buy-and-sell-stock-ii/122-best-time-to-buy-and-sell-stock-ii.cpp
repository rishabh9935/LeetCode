class Solution {
public:
    int help(int i, vector<int>& prices, int buy, vector<vector<int>>& dp){
        if(i == prices.size()) return 0;
        int profit;
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        if(buy){
            profit = max((-prices[i]) + help(i+1, prices, 0, dp), help(i+1, prices, 1, dp));
        }
        else{
            profit = max(prices[i] + help(i+1, prices, 1, dp), help(i+1, prices, 0, dp));
        }
        return dp[i][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return help(0, prices, 1, dp);
    }
};