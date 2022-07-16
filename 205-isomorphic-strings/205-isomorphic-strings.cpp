class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        map<char, char> mp1;
        map<char, bool> mp2;
        for(int i=0;i<s.size();i++){
            if(mp1.find(s[i])!=mp1.end()){
                if(mp1[s[i]]!=t[i]) return false;
            } else{
                if(mp2.find(t[i])!=mp2.end()){
                    return false;
                } else{ 
                    mp1[s[i]] = t[i];
                    mp2[t[i]] = true;
                }
            }
        }
        return true;
    }
};