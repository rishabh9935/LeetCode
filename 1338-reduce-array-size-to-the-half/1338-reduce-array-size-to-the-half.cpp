class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        vector<int> vec;
        for(auto it : mp){
            vec.push_back(it.second);
        }
        sort(vec.begin(), vec.end());
        int count = 0;
        int temp = n;
        for(int i=vec.size()-1;i>=0;i--){
            temp -= vec[i];
            if(temp <= n/2){
                count++;
                break;
            }
            count++;
        }
        return count;
    }
};