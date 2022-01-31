class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> x;
        if(intervals.size()==0)
            return x;
        sort(intervals.begin(),intervals.end());
        vector<int> ans = intervals[0];
        for(auto it : intervals){
            if(it[0] <= ans[1]){
                ans[1]=max(it[1],ans[1]);
            }
            else{
                x.push_back(ans);
                ans=it;
            }
        }
        x.push_back(ans);
        return x;
    }
};