class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans;
        int x = 0;
        for(auto it : nums){
            if(it%2 == 0) x+=it;
        }
        for(int i=0;i<n;i++){
            int y = nums[queries[i][1]];
            if(y % 2 == 0){
                int z = nums[queries[i][1]] + queries[i][0];
                if(z%2 != 0){
                    x = x-y;
                    nums[queries[i][1]] += queries[i][0];
                    ans.push_back(x);
                }
                else{
                    int m = z - y;
                    x += m;
                    nums[queries[i][1]] += queries[i][0];
                    ans.push_back(x);
                }
            }
            else{
                int z = nums[queries[i][1]] + queries[i][0];
                if(z%2 != 0){
                    nums[queries[i][1]] += queries[i][0];
                    ans.push_back(x);
                }
                else{
                    nums[queries[i][1]] += queries[i][0];
                    x += nums[queries[i][1]];
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};

// if(z%2 != 0){
//                 x = x-y;
//                 nums[queries[i][1]] += queries[i][0];
//                 ans.push_back(x);
//             }
//             else{
//                 int m = z - y;
//                 x += m;
//                 nums[queries[i][1]] += queries[i][0];
//                 ans.push_back(x);
//             }
            


// nums[queries[i][1]] += queries[i][0];
//             int x = 0;
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i] % 2 == 0){
//                     x += nums[i];
//                 }
//             }
//             ans.push_back(x);