class Solution {
public:
    int reverse(int x) {
        if(x>= (pow(2,31)-1) || x <= pow(-2,31)) 
            return 0;
        long rev=0,rem;
         while(x!=0){
            rem = x%10;
            rev = rev*10 + rem;
            x=x/10;
            }
            // x=rev;
        if(rev>= (pow(2,31)-1) || rev <= pow(-2,31)) 
            return 0;
        else 
            return rev;   
    }
};