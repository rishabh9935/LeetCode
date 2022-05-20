class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        string ans= "";
        int i=m;
        int j=n;
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                ans.push_back(text1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(text1[i-1]);
                    i--;
                }
                else{
                    ans.push_back(text2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            ans.push_back(text1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(text2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};