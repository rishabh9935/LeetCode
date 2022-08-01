class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        stack<int> s;
        vector<int> ans(n2);
        vector<int> ans2(n1);
        s.push(-1);
        for(int i=n2-1;i>=0;i--){
            int curr = nums2[i];
            while(s.top() != -1 && s.top() < curr)
                s.pop();
            ans[i] = s.top();
            s.push(curr);
        }
        for(int i=0;i<n1;i++){
            int find = nums1[i];
            for(int j=0;j<nums2.size();j++){
                if(nums2[j] == find){
                    ans2[i] = ans[j];
                }
            }
        }
        return ans2;
    }
};