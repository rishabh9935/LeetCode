class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        int ans = 0;
        bool flag = 0;
        for(auto i = mp.begin(); i != mp.end(); i++){
            string temp = i->first;
            swap(temp[0], temp[1]);
            if(i->first != temp){
                if(mp.find(temp) != mp.end()){
                    ans += min(mp[i->first], mp[temp])*4;
                    mp[i->first] = 0;
                    mp[temp] = 0;
                }
            }
                
            else {
                if(mp[i->first] > 1){
                    if((mp[i->first] % 2) == 0){
                        ans += mp[i->first]*2;
                        mp[i->first] = 0;
                    }
                    else{
                        ans += (mp[i->first]-1)*2;
                        mp[i->first] = 1;
                    }
                }
                if(mp[i->first] == 1 && flag == 0){
                    ans += 2;
                    flag = 1;
                    mp[temp]--;
                }
            }
            
        }
        return ans;
    }
};