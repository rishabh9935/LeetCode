class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> mp;
        for(int i=0;i<s.size();i++)
            mp[s[i]].push_back(i);
        int cnt = 0;
        for(int i=0;i<words.size();i++){
            bool isSeq = true;
            int lastO = -1;
            for(char w : words[i]){
                auto it = upper_bound(mp[w].begin(), mp[w].end(), lastO);
                if(it==mp[w].end()){
                    isSeq = false;
                    break;
                }
                else lastO = *it;
            }
            if(isSeq) cnt++;
        }
        return cnt;
    }
};