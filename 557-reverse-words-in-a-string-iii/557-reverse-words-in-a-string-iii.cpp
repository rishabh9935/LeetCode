class Solution {
public:
    void rev(int i, int j, string &s){
        while(i<j){
            swap(s[i++], s[j--]);
        }
    }
    
    string reverseWords(string s) {
        int i = 0;
        int j = 0;
        int n = s.length();
        while(j <= n){
            if(j == n){
                rev(i, j-1, s);
            }
            if(s[j] == ' '){
                rev(i, j-1, s);
                i = j+1;
                j = j+1;
            }
            else{
                j++;
            }
        }
        return s;
    }
};