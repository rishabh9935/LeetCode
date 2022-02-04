// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &Arr , int N){
        int sum = 0;
        for(int i=0;i<K;i++){
            sum+=Arr[i];
        }
        int maxi = sum;
        for(int i=1;i<=N-K;i++){
            sum = sum - Arr[i-1];
            sum = sum + Arr[i+K-1];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends