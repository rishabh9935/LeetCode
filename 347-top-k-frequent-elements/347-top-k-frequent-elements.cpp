class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(auto i=umap.begin();i!=umap.end();i++){
            minh.push({i-> second,i->first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        while(minh.size()!=0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};