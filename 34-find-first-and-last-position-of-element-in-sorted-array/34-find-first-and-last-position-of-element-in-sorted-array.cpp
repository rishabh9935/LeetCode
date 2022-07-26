class Solution {
public:
    void Starting(vector<int>& nums, int target, int s, int e,int &res){
        if(s<=e){
            int mid = s + (e-s/2);
            if(nums[mid]==target){
                res = mid;
                Starting(nums, target, s, mid-1, res);
            }
            else if(target<nums[mid]){
                Starting(nums, target, s, mid-1, res);
            }
            else{
                Starting(nums, target, mid+1, e, res);
            }
        }
        // return res;
    }
    void Ending(vector<int>& nums, int target, int s, int e,int &re){
        if(s<=e){
            int mid = s + (e-s/2);
            if(nums[mid]==target){
                re = mid;
                Ending(nums, target, mid+1, e, re);
            }
            else if(target<nums[mid]){
                Ending(nums, target, s, mid-1, re);
            }
            else{
                Ending(nums, target, mid+1, e, re);
            }
        }
        // return res;
    }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> v(2);
        int r1 = -1;
        int r2 = -1;
        Starting(nums, target, 0, n-1, r1);
        Ending(nums, target, 0, n-1, r2);
        v[0] = r1;
        v[1] = r2;
        return v;
    }
};