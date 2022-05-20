// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std; 

 // } Driver Code Ends

class Solution{
    public:
    bool isSubSequence(string A, string B) 
    {
        int j=0;
        for(int i=0;i<B.size();i++){
            if(B[i]==A[j]){
                j++;
            }
        }
        if(j==A.size())
        return true;
        else
        return false;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;  
        Solution ob;
        if(ob.isSubSequence(A,B))
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
    }
    return 0; 
} 
  // } Driver Code Ends