class Solution {
public:
    int M = 1000000007;
    int solve(int n,int k,int target,vector<vector<int>> &dp){
        if(n==0 && target==0) return 1;
        if(n<0 || target<=0) return 0;
        if(dp[n][target]!=-1) return dp[n][target];
        
        int ways = 0;
        for(int j = 1;j<=k;j++){
            ways = (ways + solve(n-1,k,target-j,dp))%M;
        }
        return dp[n][target] = ways%M;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};