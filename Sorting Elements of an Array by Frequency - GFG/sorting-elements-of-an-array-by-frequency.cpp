#include <bits/stdc++.h>
using namespace std;

vector<int> sortByFreq(vector<int> nums){
    vector<int> v;
    unordered_map<int,int> umap;
    for(int i=0;i<nums.size();i++){
        umap[nums[i]]++;
    }
    priority_queue<pair<int,int>> maxh;
    for(auto i=umap.begin();i!=umap.end();i++){
         maxh.push({i-> second,-1*(i->first)});
    }
    while(maxh.size()!=0){
        int freq = maxh.top().first;
        int ele = maxh.top().second;
        for(int i=0;i<freq;i++){
            v.push_back(-1*ele);
        } 
        maxh.pop();
    }
    return v;
}


int main() {
    int t;
    cin>>t;
    while(t>0){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        vector<int> ans = sortByFreq(nums);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        t--;
    }
	return 0;
}
