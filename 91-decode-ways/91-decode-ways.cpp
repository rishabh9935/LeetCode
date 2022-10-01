class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = s[0] == '0' ? 0 : 1;
        int prev = s[0] - '0';
        
        for(int i = 1; i < n; i++) {
            if (s[i] != '0') 
                dp[i] += dp[i - 1];
            
            if (prev == 1 || (prev == 2 && s[i] - '0' <= 6))
                dp[i] += i == 1 ? 1 : dp[i - 2];
            
            prev = s[i] - '0';
        }
        
        return dp[n - 1];
    }
};