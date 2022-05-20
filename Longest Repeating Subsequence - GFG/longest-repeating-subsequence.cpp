// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int m = str.size();
		    int n = m;
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
                    if(str[i-1]==str[j-1] && i!=j){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else
                        dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
            return dp[m][n];
    	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends