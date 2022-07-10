class Solution {
public:
    bool checkCyc(vector<vector<int>>& adj, int node, int vis[], int dfsVis[]){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it : adj[node]){
            if(vis[it]==0){
                if(checkCyc(adj, it, vis, dfsVis)) return true;
            }else if(dfsVis[it]==1){
                return true;
            }
        }
        dfsVis[node]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0 ; i<prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int vis[numCourses], dfsVis[numCourses];
        memset(vis, 0, sizeof vis);
        memset(dfsVis, 0, sizeof dfsVis);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(checkCyc(adj, i, vis, dfsVis)) return false;
            }
        }
        return true;
    }
};