class Solution {
public:
    
    int perfectSum(vector<int> arr, int n, int sum)
	{
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
        int sum = 0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        sum+=target;
        if(sum%2==1 || sum<0) return 0;
        int s1 = sum/2;
        return perfectSum(nums,nums.size(),s1);
    }
};