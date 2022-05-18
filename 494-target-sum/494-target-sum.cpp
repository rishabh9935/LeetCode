class Solution {
public:
    int perfectSum(vector<int> arr, int n, int sum)
	{
	    long long m = 1e9 + 7;
        int dp[n+1][sum+1];
        dp[0][0] = 1;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = 0;
     
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][sum];
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for(int i=0;i<nums.size();i++)
            total+=nums[i];
        total-=target;
        if(total%2==1 || total<0) return 0;
        int sum = total/2;
        return perfectSum(nums,nums.size(),sum);
//         int n=nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//         }
        
//         sum-=target;
//         if(sum%2==1 || sum<0)
//             return 0;
//         int w=sum/2;
//         vector<vector<int>>dp(n+1,vector<int>(w+1,0));
//         for(int i=0;i<=n;i++){
//             dp[i][0]=1;
//         }
//         for(int i=1;i<=w;i++){
//             dp[0][i]=0;
//         }
//         for(int i=1;i<=n;i++){
//             for(int j=0;j<=w;j++){
//                 if(nums[i-1]<=j)
//                     dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
//                 else
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[n][w];
    }
};