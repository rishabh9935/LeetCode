class NumArray {
public:
    vector<int> nums1;
    int sum;
    NumArray(vector<int>& nums) {
        this->nums1 = nums;
        sum = 0;
        for(auto i : nums1) sum+=i;
    }
    
    void update(int index, int val) {
        sum = sum - nums1[index] + val;
        nums1[index] = val;
        
    }
    
    int sumRange(int left, int right) {
        int ans = sum;
        for(int i=0;i<left;i++){
            ans = ans - nums1[i];
        }
        for(int i=right+1;i<nums1.size();i++){
            ans = ans - nums1[i];
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */