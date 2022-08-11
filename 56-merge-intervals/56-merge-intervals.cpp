class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp(2);
        if(intervals.size()==0)
            return ans;
        sort(intervals.begin(),intervals.end());
        temp[0] = intervals[0][0];
        temp[1] = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= temp[1]){
                temp[1] = max(temp[1], intervals[i][1]);
            }
            else{
                ans.push_back(temp);
                temp[0] = intervals[i][0];
                temp[1] = intervals[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};