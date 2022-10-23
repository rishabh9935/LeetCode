class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> mp;
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){
                ans[0] = nums[i];
            }
            mp[nums[i]]++;
        }
        
        for(int i=1;i<=n;i++){
            if(mp.count(i) == false){
                ans[1] = i;
                break;
            }
        }
        return ans;
    }
};