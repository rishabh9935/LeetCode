class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int i = 0 , j = 0 ;
        unordered_map<char, int> um;
        int maxi = 0;
        while(j<n){
            um[s[j]]++;
            if(um.size() == j-i+1){
                maxi = max(maxi, j-i+1);
                j++;
            }
            else if(um.size() < j-i+1){
                while(um.size() < j-i+1){
                    um[s[i]]--;
                    if(um[s[i]]==0)
                        um.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }
};