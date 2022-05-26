class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        for(int i=0;i<=31;i++){
            if(n%2==1) cnt++;
            n=n/2;
        }
        return cnt;
    }
};