class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> mp;
        map<char, int> mp1;
        for(int i=0;i<s.size();i++) mp[s[i]]++;
        
        for(int i=0;i<t.size();i++) mp1[t[i]]++;
        
        if(mp.size() != mp1.size()) return false;
        
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second != mp1[it->first]){
                return false;
            }
        }
        
        return true;
    }
};