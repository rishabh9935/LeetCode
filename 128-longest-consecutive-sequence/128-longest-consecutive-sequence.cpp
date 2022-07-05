class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1) return nums.size();
        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]) v.push_back(nums[i]);
        }
        if(v.size()<=1) return v.size();
        int c = 1;
        for(int i=1;i<v.size();i++){
            int j = i-1;
            if(v[j]+1==v[i]){
                c++;
            }
            else c=1;
            maxi = max(maxi,c);
        }
        return maxi;
    }
};