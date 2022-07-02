class Solution {
public:
    // int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    //     horizontalCuts.push_back(h);
    //     horizontalCuts.push_back(0);
    //     verticalCuts.push_back(w);
    //     verticalCuts.push_back(0);
    //     sort(horizontalCuts.begin(),horizontalCuts.end());
    //     sort(verticalCuts.begin(),verticalCuts.end());
    //     int maxh = 0 , maxv = 0;
    //     for(int i=0;i<horizontalCuts.size()-1;i++){
    //         maxh = max(maxh,horizontalCuts[i+1]-horizontalCuts[i]);
    //     }
    //     for(int i=0;i<verticalCuts.size()-1;i++){
    //         maxv = max(maxv,verticalCuts[i+1]-verticalCuts[i]);
    //     }
    //     int mod = 1e9 + 7;
    //     return maxh*maxv % mod;
    // }
    int maxArea(int h, int w, vector<int>& horizontal, vector<int>& vertical) {
        sort(begin(horizontal), end(horizontal));              // n(logn)
        sort(begin(vertical), end(vertical));                       // n(logn)
        
        long long hmx = 0, vmx = 0, prev = 0;
        
        for(auto i: horizontal)                                          // O(n)  
            hmx = max(hmx, i - prev), prev = i;
        hmx = max(hmx, h - prev);
        
        prev = 0;
        for(auto i: vertical)                                              // O(n)  
            vmx = max(vmx, i - prev), prev = i;
        vmx = max(vmx, w - prev);
        
        int mod = 1e9 + 7;
        return hmx * vmx % mod;
    }
};