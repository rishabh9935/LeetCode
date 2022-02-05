// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long getSubstringWithEqual012(string str) {
        long long int ans=0;
        long long int count0 = 0;
        long long int count1 = 0;
        long long int count2 = 0;
        unordered_map <string, long long> um;
        string diff01;
        string diff12;
        string key ;
        for(int i=0;i<str.length();i++){
            if(str[i]=='0')
                count0++;
            else if(str[i]=='1')
                count1++;
            else
                count2++;
            diff01 = to_string(count1 - count0);
            diff12 = to_string(count2 - count1);
            key = diff12 + "#" + diff01;
            if(count1 - count0 == 0 && count2 - count1 == 0){
                ans++;
            }
            if(um.find(key)!=um.end()){
                ans+=um[key];
            }
                um[key]++;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.getSubstringWithEqual012(s)<<endl;
	}
    return 0;
}
  // } Driver Code Ends