class Solution {
public:
    int subarraySum(vector<int>& nums, int k){
        int n = nums.size();
        int curr = 0;
        int count = 0;
        unordered_map<int , int> map;
        // map[0]=1;  // we can also use the commented statement below instead of this
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(curr-k==0){
                count++;
            }
            if(map.find(curr-k)!=map.end()){
                count = count + map[curr-k];
            }
            map[curr]++;
        }
        return count;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        for(int i=0;i<m;i++){
            vector<int> sumRow(n,0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    sumRow[k] += matrix[j][k];
                }
                ans += subarraySum(sumRow, target);
            }
        }
        return ans;
    }
};