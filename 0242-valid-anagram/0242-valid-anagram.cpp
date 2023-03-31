class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp1;
        map<char, int> mp2;
        if(s.length() != t.length())
            return false;
        
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        
        for(auto i : mp1){
            if(i.second != mp2.find(i.first)->second)
                return false;
        }
        
        return true;
    }
};