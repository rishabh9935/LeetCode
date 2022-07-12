class Solution {
public:
    
    bool dfs(vector<int> &matchsticks, int target,vector<int> &sides, int idx){
        if(idx == matchsticks.size()){
            if(sides[0]==sides[1] && sides[1]==sides[2] && sides[2]==sides
               [3])
                return true;
            return false;
        }
        for(int i=0; i<4; i++){
            if(sides[i] + matchsticks[idx] <= target){
                sides[i] += matchsticks[idx];
                if(dfs(matchsticks, target, sides, idx+1))
                    return true;
                sides[i] -= matchsticks[idx];
            } 
        }
        return false;
    }
    
    
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() == 0) return false;
        
        int sum = 0;
        for(int i=0;i<matchsticks.size();i++){
            sum += matchsticks[i];
        }
        if(sum%4 != 0) return false;
        int target = sum/4;
        vector<int> sides(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        if(matchsticks[0]>target) return false;
        
        return dfs(matchsticks, target, sides, 0);
    }
};



