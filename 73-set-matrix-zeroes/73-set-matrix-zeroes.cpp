class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <pair<int,int>> v;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0) v.push_back({i,j});
            }
        }
        for(auto it : v){
            for(int k=0;k<matrix.size();k++)
                matrix[k][it.second] = 0;
                
            for(int j=0;j<matrix[0].size();j++)
                matrix[it.first][j] = 0;
        }
    }
};