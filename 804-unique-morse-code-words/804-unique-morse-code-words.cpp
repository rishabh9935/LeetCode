class Solution {
public:
    string transform(string word, vector<string> vec){
        string ans = "";
        for(int i=0;i<word.size();i++){
            ans += vec[word[i] - 'a'];
        }
        return ans;
    } 
    
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> vec{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> st;
        for(int i=0;i<words.size();i++){
            string s = transform(words[i], vec);
            st.insert(s);
        }
        return st.size();
    }
};