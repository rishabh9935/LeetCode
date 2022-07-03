class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int i = 1; while(i < nums.size() && nums[i] == nums[i-1]) i++;
        if(i == nums.size()) return 1;

        int c = 2;
        bool inc = nums[i] > nums[i-1];
        while(i < nums.size()) {
            if(inc) {
                while(i < nums.size() && nums[i] >= nums[i-1]) i++;
                if(i < nums.size()) c++; inc = false;
            }
            else {
                while(i < nums.size() && nums[i] <= nums[i-1]) i++;
                if(i < nums.size()) c++; inc = true;
            }

        }
        return c;
    }
};