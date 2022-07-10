// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool checkCyc(vector<int> adj[], int node, int vis[], int dfsVis[]){
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
    // Function to detect cycle in a directed graph.
    bool isCyclic(int numCourses, vector<int> adj[]) {
        int vis[numCourses], dfsVis[numCourses];
        memset(vis, 0, sizeof vis);
        memset(dfsVis, 0, sizeof dfsVis);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                if(checkCyc(adj, i, vis, dfsVis)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends