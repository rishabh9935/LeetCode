class Solution {
public:
    bool biper(int src, int color[], vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<graph[node].size();i++){
                int it = graph[node][i];
                if(color[it] == -1){
                    color[it] = 1 - color[node];
                    q.push(it);
                }else if(color[it] == color[node]) return false;
                else continue;
            }
        }
        return true;
    }
    
    bool checkbipertite(vector<vector<int>>& graph,int n){
        int color[n];
        memset(color, -1, sizeof color);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!biper(i, color, graph)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        return checkbipertite(graph, n);
        
    }
};