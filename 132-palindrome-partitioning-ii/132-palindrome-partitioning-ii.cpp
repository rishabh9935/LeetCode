class Solution {
public:
    int dp[2001][2001];
    bool isPalindrome(string &s,int i,int j){
        if(i==j) return true;
        if(i>j) return true;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    int solve(string &str,int i,int j){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)==true) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            if(!isPalindrome(str,i,k)) continue;
            int left,right;
            if(dp[i][k]!=-1)
                left = dp[i][k];
            else{
                left = solve(str,i,k);
                dp[i][k] = left;
            }
            if(dp[k+1][j]!=-1)
                right = dp[k+1][j];
            else{
                right = solve(str,k+1,j);
                dp[k+1][j] = right;
            }
            int temp = 1+left+right;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int minCut(string str) {
        int N = str.size();
        memset(dp,-1,sizeof(dp));
        int i=0;
        int j=N-1;
        return solve(str,i,j); 
    }
    
};