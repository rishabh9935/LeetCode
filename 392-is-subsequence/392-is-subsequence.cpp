class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        for(i=0;i<t.size();i++){
            if(j==s.size()) return true;
            if(t[i]==s[j]){
                j++;
            } 
        }
        if(j==s.size() && i==t.size()) return true;
        return false;
    }
};