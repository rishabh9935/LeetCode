class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> ans = mat;
        for(int i=row-1;i>=0;i--){
            vector<int> v;
            int x=i;
            int y=0;
            while(x<row && y<col){
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x=i;
            y=0;
            for(auto i:v){
                ans[x][y] = i;
                x++;
                y++;
            }
            v.clear();
        }
        for(int i=1;i<col;i++){
            vector<int> v;
            int x=0;
            int y=i;
            while(x<row && y<col){
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x=0;
            y=i;
            for(auto i:v){
                ans[x][y] = i;
                x++;
                y++;
            }
            v.clear();
        }
        return ans;
    }
};