class Solution {
public:
    int help(int i, vector<int>& prices, int cap,int buy, vector<vector<vector<int>>> &dp){
        if(i == prices.size() || cap == 0) return 0;
        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap] = max(-prices[i] + help(i+1, prices, cap, 0, dp), 
                        0 + help(i+1, prices, cap, 1, dp));
        }
        
        return dp[i][buy][cap] = max(prices[i] + help(i+1, prices, cap-1, 1, dp),
                                     0 + help(i+1, prices, cap, 0, dp));
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
        return help(0, prices, 2, 1, dp);
    }
};