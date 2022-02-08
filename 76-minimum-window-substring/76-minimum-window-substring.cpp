class Solution {
public:
    string minWindow(string s, string t) {
        int x , y;
        unordered_map<char, int> m;
        for(int i=0;i<t.length();i++){
            m[t[i]]++;
        }
        int count = m.size();
        int i = 0;
        int j = 0;
        string ans;
        int mini = INT_MAX;
        while (j<s.length())
        {
            if(count>0){
                if(m.find(s[j]) != m.end()){
                    m[s[j]]--;
                    if(m[s[j]]==0){
                        count--;
                    }
                }
            }
            if(count==0){
                while(count==0){
                    if(m.find(s[i]) != m.end()){
                        m[s[i]]++;
                        if(mini>j-i+1){
                            mini = j-i+1;
                            x = i;
                            y = j;
                        }
                        if(m[s[i]]==1){
                            count++;
                        }
                    }
                    i++;  
                }
            }
            j++;

        }
        for (int i = x; i <= y; i++)
        {
            ans.push_back(s[i]);
        }
        return ans;
    }
};