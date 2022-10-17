class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26)
            return false;
        map<char, int> mp;
        for(auto it : sentence){
            mp[it]++;
        }
        if(mp.size() < 26)
            return false;
        return true;
    }
};