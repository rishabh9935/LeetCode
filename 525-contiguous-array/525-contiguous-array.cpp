class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
                nums[i]=-1;
        }
        int maxi=0;
        int start=0;
        int end=-1;
        int curr=0;
        unordered_map <int , int> map;
        // map[0]=1;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            if(curr==0){
                start=0;
                end=i+1;
                int x = end - start;
                maxi=max(maxi,x);
            }
            if(map.find(curr)!=map.end()){
                start=map[curr];
                end=i;
                int x = end - start;
                maxi=max(maxi,x);
            }
            else{
                map[curr]=i;
            }
            
        }
        return maxi;
    }
};