class Solution {
public:
    map<char, int> giveFreq(string s){
        map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        return mp;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        map<char, int> max_m;
        
        for(int i=0;i<words2.size();i++){
            map<char, int> mp;
            mp = giveFreq(words2[i]);
            for(auto it : mp){
                max_m[it.first] = max(max_m[it.first], mp[it.first]);
            }
        }
        
        for(int i=0;i<words1.size();i++){
            map<char, int> m;
            m = giveFreq(words1[i]);
            bool flag = true;
            for(auto it : max_m){
                if(m[it.first] < max_m[it.first]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(words1[i]);
        }
        return ans;
    }
};