// class Solution {
// public:
//     bool isPalindrome(string& s){
//         int x = 0;
//         int y = s.length()-1;
//         while(x<y){
//             if(s[x] == s[y]){
//                 x++;
//                 y--;
//             }
//             else return false;
//         }
//         return true;
//         // while(x<y){if(s[x++] != s[y--]) return false;}
//         // return true;
//     }
    
    
//     vector<vector<int>> palindromePairs(vector<string>& words) {
//         vector<vector<int>> ans;
//         int n = words.size();
//         if(n < 2) return ans;
//         unordered_map<string, int> mp;
        
//         for(int i=0;i<words.size();i++){
//             auto s = words[i];
//             reverse(s.begin(), s.end());
//             mp[s] = i;
//         }
        
//         for(int i=0;i<words.size();i++){
//             for(int j=0;j<=words[i].size();j++){
//                 string st1 = words[i].substr(0, j);
//                 string st2 = words[i].substr(j);
//                 if(mp.count(st1) && isPalindrome(st2) && mp[st1] != i){
//                     ans.push_back({i, mp[st1]});
//                 }
//                 if(!st1.empty() && mp.count(st2) && isPalindrome(st1) && mp[st2] != i){
//                     ans.push_back({mp[st2], i});
//                 }
//             }
//         }
//         return ans;
//     }
// };

struct TrieNode
{
    TrieNode *child[26]={};
    int curIndex=-1;
    vector<int> wordIndex;
};
class Solution
{
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }
    TrieNode *root;
    void insert(string &s, int index)
    {
        TrieNode *cur = root;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (cur->child[c] == nullptr)
                cur->child[c] = new TrieNode();
            if (isPalindrome(s, 0, i))
                cur->wordIndex.push_back(index);
            cur = cur->child[c];
        }
        cur->wordIndex.push_back(index);
        cur->curIndex = index;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);
        vector<vector<int>> ans;
        for (int i = 0; i < words.size(); i++)
        {
            TrieNode *cur = root;
            string &s = words[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (cur->curIndex != -1 && cur->curIndex != i && isPalindrome(s, j, s.size() - 1))
                    ans.push_back({i, cur->curIndex});
                cur = cur->child[s[j] - 'a'];
                if (cur == nullptr)
                    break;
            }
            if (cur == nullptr)
                continue;
            for (int j : cur->wordIndex)
            {
                if (i == j)
                    continue;
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};