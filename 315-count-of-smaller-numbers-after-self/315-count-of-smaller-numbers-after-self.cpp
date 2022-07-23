class Solution {
public:
    void merge(vector<pair<int, int>> &v, vector<int> &count, int s, int e, int m){
        vector<pair<int, int>> temp(e-s+1);
        int i = s;
        int j = m+1;
        int k = 0;
        while(i<=m && j<=e){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += e-j+1;
                temp[k++] = v[i++];
            }
        }
        while(i<=m) temp[k++]=v[i++];
        while(j<=e) temp[k++]=v[j++];
        for(int i=s;i<=e;i++)
            v[i] = temp[i-s];
    }
    
    void mergeSort(vector<pair<int, int>> &v, vector<int> &count, int s, int e){
        if(s>=e) return;
        int m = s + ((e-s)/2);
        mergeSort(v, count, s, m);
        mergeSort(v, count, m+1, e);
        merge(v, count, s, e, m);
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        vector<int> count(n, 0);
        mergeSort(v, count, 0, n-1);
        return count;
    }
};