// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int lcs(int m, int n, string text1, string text2)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));  
        // int dp[m+1][n+1];
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
        return dp[m][n];
    }
    int countMin(string str){
        string s = str;
        reverse(str.begin(),str.end());
        int m = str.size();
        int x = lcs(m,m,str,s);
        return m - x;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

  // } Driver Code Ends