class Solution {
public:
    int solve(int sum){
        if(sum%10 == sum)
            return sum;
        int add=0;
        while(sum != 0){
            int l = sum%10;
            sum = sum/10;
            add += l;
        }
        return solve(add);
    }
    
    int addDigits(int num) {
        // int sum = 0;
        // while(num != 0){
        //     int l = num%10;
        //     num = num/10;
        //     sum += l;
        // }
        int x = solve(num);
        return x;
    }
};