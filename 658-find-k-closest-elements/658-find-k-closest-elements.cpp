class Solution {
public:
    vector<int> findClosestElements(vector<int>& v, int k, int x) {
        priority_queue<pair<int,int>> maxh;
        vector<int> ans;
        for(int i=0;i<v.size();i++){
            maxh.push({abs(v[i]-x),v[i]});   
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        while(maxh.size()!=0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};