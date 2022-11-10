class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            // char temp = st.top();
            if(st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans = "";
        while(!st.empty()){
            // char x = st.top();
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // string ans;
        // char prev;
        // for(int i=0;i<s.size();i++){
        //     char x = s[i];
        //     if(x==prev){
        //         continue;
        //     }
        //     ans = ans + s[i];
        //     prev = s[i];
        // }
        // return ans;
    }
};