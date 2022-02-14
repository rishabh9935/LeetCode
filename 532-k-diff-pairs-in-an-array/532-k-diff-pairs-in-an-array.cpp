class Solution {
public:
    int findPairs(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int i=0;
        int j=1;
        int count = 0;
        while(j<v.size() && i<v.size()){
            if(v[j]-v[i] < k){
                j++;
            }
            else if(v[j]-v[i]==k){
                count++;
                i++;
                j++;
                while(j<v.size() && v[j] == v[j-1]){
                    j++;
                }
            }
            else{
                i++;
                if(j-i==0)
                    j++;
            }
        }
        return count;
    }
};