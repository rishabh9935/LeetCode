class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        if(n%2 != 0) return ans;
        sort(changed.begin(), changed.end());
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[changed[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[changed[i]] == 0){
                continue;
            }
            if(mp[changed[i]*2] == 0) return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[changed[i]*2]--;
        }
        return ans;
        
    }
};