// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    int n = s.length();
    int i = 0;
    int j = 0;
    int maxi = -1;
    unordered_map<char, int> um;
    while(j<n){
        um[s[j]]++;
        if(um.size()<k){
            j++;
        }
        else if(um.size()==k){
            maxi = max(maxi, j-i+1);
            j++;
        }
        else if(um.size()>k){
            while(um.size()>k){
                um[s[i]]--;
                if(um[s[i]]==0)
                    um.erase(s[i]);
                i++;
            }
            j++;
        }
    }
    return maxi;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends