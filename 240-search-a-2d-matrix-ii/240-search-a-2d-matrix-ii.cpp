class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0 , col = n-1;
        while(row<m && col>=0){
            int pivot = matrix[row][col];
            if(pivot == target){
                return true;
            }
            else if(pivot < target){
                row++;
            }
            else col--;
        }
        return false;
    }
};