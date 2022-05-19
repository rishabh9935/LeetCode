class Solution {
public:
    int LCS(string &X,string &Y,int n,int m,vector<vector<int>>&t){
        if(n==0 || m==0)
            return 0;
        if(t[n][m]!=-1) return t[n][m];
        if(X[n-1]==Y[m-1])
            return t[n][m] = 1 + LCS(X,Y,n-1,m-1,t);
        else
            return t[n][m] = max(LCS(X,Y,n,m-1,t),LCS(X,Y,n-1,m,t));
    }
    int longestCommonSubsequence(string text1, string text2) {
        // memset(t,-1,sizeof(t));
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>t(n+1,vector<int>(m+1,-1));
        return LCS(text1,text2,n,m,t);
    }
    // int f(string &s1,string &s2, int idx1, int idx2, vector<vector<int>>&dp){
    //     if(idx1<0 || idx2<0) return 0;
    //     if(dp[idx1][idx2]!=-1){
    //         return dp[idx1][idx2];
    //     }
    //     if(s1[idx1]==s2[idx2]){
    //         return dp[idx1][idx2]= 1+f(s1,s2,idx1-1,idx2-1,dp);
    //     }
    //     return dp[idx1][idx2]=max(f(s1,s2,idx1-1,idx2,dp),f(s1,s2,idx1,idx2-1,dp));
    // }
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n=s1.size();
    //     int m=s2.size();
    //     vector<vector<int>>dp(n,vector<int>(m,-1));
    //     return f(s1,s2,n-1,m-1,dp);
    // }
};