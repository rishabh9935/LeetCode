class Solution {
public:
    int dp[101][10001];
    int solve(int e,int f){
        if(f==0 || f==1) return f;
        if(e==1) return f;
        if(dp[e][f]!=-1) return dp[e][f];
        int mn = INT_MAX;
        int l=1,h=f;
        int k;
        while(l <= h){
            int k=(h+l)/2;
            int left , right;
            if(dp[e-1][k-1] != -1)
                left = dp[e-1][k-1];
            else{
                left = solve(e-1,k-1);
                dp[e-1][k-1] = left;
            }
            if(dp[e][f-k]!=-1)
                right = dp[e][f-k];
            else{
                right = solve(e,f-k);
                dp[e][f-k] = right;
            }
            int temp = 1 + max(left,right);
            mn = min(mn,temp);
            if(left < right)
                l = k+1;
            else
                h = k-1;
            
        }
        return dp[e][f] = mn;
    }
    int superEggDrop(int k, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(k,n);
    }
};