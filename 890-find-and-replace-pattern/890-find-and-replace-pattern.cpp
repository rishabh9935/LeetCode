class Solution {
public:
    bool match(string word, string pattern){
        map<char, char> mp1;
        map<char, char> mp2;
        if(word.size()!=pattern.size()) return false;
        for(int i=0;i<word.size();i++){
            if(mp1.find(word[i]) != mp1.end()){
                if(mp1[word[i]] != pattern[i]){
                    return false;
                }
            }
            else if(mp2.find(pattern[i])!=mp2.end()){
                if(mp2[pattern[i]] != word[i])
                    return false;
            }
            mp1[word[i]] = pattern[i];
            mp2[pattern[i]] = word[i];
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(match(words[i], pattern)){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};