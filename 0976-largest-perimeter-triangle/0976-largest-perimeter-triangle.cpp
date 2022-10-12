class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = nums.size()-1;
        while(x != 1){
            if(nums[x-1] + nums[x-2] > nums[x]){
                return nums[x-1]+nums[x-2]+nums[x];
            }
            x--;
        }
        return 0;
    }
};