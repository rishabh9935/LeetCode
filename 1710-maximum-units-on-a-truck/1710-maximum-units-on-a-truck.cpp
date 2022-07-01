class Solution {
public:
    // bool sortcol(const vector<int>& v1, const vector<int>& v2)
    // {
    // return v1[1] < v2[1];
    // }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(begin(boxTypes), end(boxTypes), [&](const vector<int>& v1, const vector<int>& v2){return v1[1] > v2[1];});
        int max=0;
        int i = 0;
        while(i<n){
            if(boxTypes[i][0]<truckSize){
                max += (boxTypes[i][1]*boxTypes[i][0]);
                truckSize = truckSize - boxTypes[i][0];
            }
            else{
                // int x = boxTypes[i][0] - truckSize;
                max += boxTypes[i][1]*truckSize;
                // truckSize = 0;
                break;
            }
            i++;
        }
        return max;
    }
};