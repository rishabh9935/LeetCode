// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int mod = 1003;
    map<string,int> mp;
    int solve(string S , int i , int j , bool isTrue){
        // base case
        if(i>j)
            return false;
        if(i==j){
            if(isTrue)
                return S[i]=='T';
            else
                return S[i]=='F';
        }
        
        // key initialization 
        // format : (i j T/F) => value/ans ;
        string temp = to_string(i); // i
        temp.push_back(' ');        // i_
        temp.append(to_string(j)) ; // i_j
        temp.push_back(' ');        // i_j_
        temp.append(to_string(isTrue));    // i_j_T/F
        
        if(mp.find(temp)!=mp.end()){
            return mp[temp];
        }
        
        int ans=0; 
        for(int k=i+1 ; k<j ; k+=2){
            
            int LT = solve(S,i,k-1,true);
            int LF = solve(S,i,k-1,false);
            int RT = solve(S,k+1,j,true);
            int RF = solve(S,k+1,j,false);
            
            if(S[k]=='&'){
                if(isTrue)
                    ans += LT*RT;
    
                else
                    ans += LT*RF + LF*RT + LF*RF;
                
            }
            
            if(S[k]=='|'){
                if(isTrue)
                    ans += LT*RT + LT*RF + LF*RT;
                
                else
                    ans += LF*RF;
                
            }
            
            if(S[k]=='^'){
                if(isTrue)
                    ans += LF*RT + LT*RF;
                
                else
                    ans += LF*RF + LT*RT;
                
            }
        }
        return mp[temp] = ans%mod;
    }
    int countWays(int N, string S){
      return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends