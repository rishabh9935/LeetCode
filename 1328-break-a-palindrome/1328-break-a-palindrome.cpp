class Solution {
public:
    
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        string ans = "";
        if(palindrome.length() == 1)
            return ans;
        string copy = palindrome;
        for(int i=0;i<palindrome.length()/2;i++){
            if(palindrome[i] > 'a'){
                if(palindrome[i] == 'a') 
                    copy[i] = 'b';
                else
                    copy[i] = 'a';
                
                return copy;
            }
        }
        copy[n-1] = 'b';
        return copy;
    }
};