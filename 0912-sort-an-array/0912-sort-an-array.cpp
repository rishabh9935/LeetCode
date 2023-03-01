class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int> , greater<int>> minh;
        for(auto i : nums){
            minh.push(i);
        }
        vector<int> ans;
        while(minh.size() != 0){
            ans.push_back(minh.top());
            minh.pop();
        }
        return ans;
    }
};