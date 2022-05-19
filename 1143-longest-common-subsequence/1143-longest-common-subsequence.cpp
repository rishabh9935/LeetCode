class Solution {
public:
    
    //Recursive + memoization
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
};