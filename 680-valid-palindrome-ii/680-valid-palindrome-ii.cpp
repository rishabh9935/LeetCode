class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size();
        int i = 0;
        int j = size - 1;
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return palindrome(s,i+1,j) || palindrome(s,i,j-1);
            }
        }
        return true;
    }
    bool palindrome(string s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};