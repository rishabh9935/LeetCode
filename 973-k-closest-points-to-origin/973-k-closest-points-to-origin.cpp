class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans(k);
        priority_queue<pair<int, pair<int, int>>> maxh;
        for(int i=0;i<points.size();i++){
            maxh.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],{points[i][0],points[i][1]}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        for(int i=0;i<k;i++){
            pair<int,int> p = maxh.top().second;
            maxh.pop();
            ans[i]={p.first,p.second};
        }
        return ans;
    }
};