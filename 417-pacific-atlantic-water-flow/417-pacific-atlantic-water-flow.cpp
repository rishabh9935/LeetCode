class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        if(heights.size()<1) return ans;
        vector<vector<int>> pacific(heights.size(), 
                                    vector<int>(heights[0].size(), 0));
        vector<vector<int>> atlantic(heights.size(), 
                                    vector<int>(heights[0].size(), 0));
        
        for(int i=0;i<heights[0].size();i++){
             func(heights, 0, i,INT_MIN, pacific);
             func(heights, heights.size()-1, i,INT_MIN, atlantic);
        }
        
        for(int i=0;i<heights.size();i++){
             func(heights, i, 0,INT_MIN, pacific);
             func(heights, i, heights[0].size()-1,INT_MIN, atlantic);
        }
        
        for(int i=0;i<heights.size();i++){
            for(int j=0;j<heights[0].size();j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
        
    }
    
    void func(vector<vector<int>>& heights, int i, int j, 
              int prev, vector<vector<int>>& ocean){
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())
            return;
        if(ocean[i][j] == 1) 
            return;
        if(heights[i][j]<prev)
            return;
        ocean[i][j] = 1;
        func(heights, i+1, j, heights[i][j], ocean);
        func(heights, i-1, j, heights[i][j], ocean);
        func(heights, i, j+1, heights[i][j], ocean);
        func(heights, i, j-1, heights[i][j], ocean);
    }
    
    
};