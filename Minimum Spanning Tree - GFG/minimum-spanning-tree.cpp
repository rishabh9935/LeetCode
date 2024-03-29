// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int cnt = 0;
        int parent[V];
        vector<int> key(V);
        bool mstSet[V];
        for(int i=0;i<V;i++){
            key[i]=INT_MAX;
            mstSet[i] = false;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0]=0;
        parent[0] = -1;
        pq.push({0, 0});
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            mstSet[u] = true;
            cnt+=key[u];
            for(auto it : adj[u]){
                int v = it[0];
                int weight = it[1];
                if(mstSet[v] == false && weight < key[v]){
                    parent[v] = u;
                    key[v] = weight;
                    pq.push({key[v], v});
                }
            }
        }
       
        // for(int i=1;i<=V;i++){
        //     cnt+=key[i];
        // }
        // return accumulate(key.begin(), key.end(), 0);
        int c = 0;
        for(int i=0;i<key.size();i++){
            c+=key[i];
        }
        return c;
    }
    
    
//     class Solution
// {
// 	public:
    
//     int spanningTree(int V, vector<vector<int>> adj[]){
//         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
//         vector<int> distance(V, INT_MAX);
//         vector<bool> visited(V, false);
        
//         distance[0] = 0;
//         pq.push({0, 0});
        
//         while(not pq.empty()){
//             int u = (pq.top()).second;
//             pq.pop();
            
//             visited[u] = true;
            
//             for(vector<int> edge : adj[u]){
//                 int v = edge[0];
//                 int w = edge[1];
                
//                 if(not visited[v] and distance[v] > w){
//                     distance[v] = w;
//                     pq.push({w, v});
//                 }
//             }
//         }
        
//         return accumulate(distance.begin(), distance.end(), 0);
//     }
// };
    
    
    
    
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends