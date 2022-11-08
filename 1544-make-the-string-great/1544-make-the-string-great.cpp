class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else if(islower(s[i])){
                if(isupper(st.top()) && (s[i] == tolower(st.top()))){
                    st.pop();
                }
                else 
                    st.push(s[i]);
            }
            else if(isupper(s[i])){
                if(islower(st.top()) && (s[i] == toupper(st.top()))){
                    st.pop();
                }
                else 
                    st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            char ch = st.top();
            ans = ans + ch;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};