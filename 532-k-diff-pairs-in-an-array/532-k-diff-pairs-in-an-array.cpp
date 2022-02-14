class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        if(k<0) return 0;
        unordered_map<int,int> m;
        int  count = 0;
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        for(auto it : m){
            if((k==0 && it.second>1) || (k && m.find(it.first+k) != m.end())){
                count++;
            }
        }
        return count;
    }
};