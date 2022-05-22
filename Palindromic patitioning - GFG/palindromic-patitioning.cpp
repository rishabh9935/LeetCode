// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s,int i,int j){
        if(i==j) return true;
        if(i>j) return true;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else
             return false;
        }
        return true;
    }
    
    int solve(string str,int i,int j,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        if(isPalindrome(str,i,j)==true) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int mn = INT_MAX;
        int left,right;
        for(int k=i;k<=j-1;k++){
            if(dp[i][k]!=-1)
                left = dp[i][k];
            else{
                left = solve(str,i,k,dp);
                dp[i][k] = left;
            }
            if(dp[k+1][j]!=-1)
                right = dp[k+1][j];
            else{
                right = solve(str,k+1,j,dp);
                dp[k+1][j] = right;
            }
            int temp = 1+left+right;
            mn = min(mn,temp);
        }
        return dp[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        int N = str.size();
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        int i=0;
        int j=N-1;
        return solve(str,i,j,dp); 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends