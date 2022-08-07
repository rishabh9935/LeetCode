class Solution {
    unordered_map<int, vector<int> > mp;
    int mod = 1e9 + 7;
public:
    
    
    int solve(int n, int curr, char prev, vector<vector<long long>> &dp){
        if(curr > n){
            return 0;
        }
        if(curr==n){
            switch(prev){
                case 'a':
                    return 1;
                case 'e':
                    return 2;
                case 'i':
                    return 4;
                case 'o':
                    return 2;
                case 'u':
                    return 1;
                default :
                    return 5;
            }
        }
        int idx = prev - 'a';
        if(dp[curr][idx] != -1)
            return dp[curr][idx];
        
        long long ans = 0;
        for(auto next : mp[prev]){
            ans += (solve(n, curr+1, next, dp) % mod);
        }
        return dp[curr][idx] = ans % mod;
    }
    
    
    int countVowelPermutation(int n) {
        mp['c'] = {'a', 'e', 'i', 'o', 'u'};
        mp['a'] = {'e'};
        mp['e'] = {'a', 'i'};
        mp['i'] = {'a', 'e', 'o', 'u'};
        mp['o'] = {'i', 'u'};
        mp['u'] = {'a'};
        vector<vector<long long> > dp(vector<vector<long long> >(n+2,vector<long long>(27,-1)));
        return solve(n, 1, 'c', dp);
    }
};