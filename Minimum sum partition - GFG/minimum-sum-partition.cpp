// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:

vector<int> isSubsetSum(int arr[], int n, int sum){
        bool dp[n+1][sum+1];
        vector<int> v;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0)
                    dp[i][j] = false;
                if(j==0)
                    dp[i][j] = true;
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j)
                    dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        for(int i=0;i<=sum/2;i++){
            if(dp[n][i]==true)
                v.push_back(i);
        }
        return v;
}
  
int minDifference(int arr[], int n)  { 
	    int Range = 0;
	    for(int i=0;i<n;i++)
	        Range+=arr[i];
	    vector<int> ans = isSubsetSum(arr,n,Range);
	    int mn = INT_MAX;
	    for(int i=0;i<ans.size();i++)
	        mn = min(mn,Range-2*ans[i]);
	    return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends