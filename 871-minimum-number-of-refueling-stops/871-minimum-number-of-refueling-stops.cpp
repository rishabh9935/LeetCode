class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int max_reach = startFuel;
        priority_queue<int> pq;
        
        int count = 0;
        int i = 0;
        while(max_reach < target){
            while(i<stations.size() && stations[i][0] <= max_reach){
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty()) return -1;
            max_reach += pq.top();
            pq.pop();
            count++;
        }
        return count;
        
    }
};