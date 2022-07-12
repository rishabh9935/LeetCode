// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	void dfs(int node, vector<int> adj[], stack<int> &st, vector<int> &vis){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it])
	            dfs(it, adj, st, vis);
	    }
	    st.push(node);
	}
	void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
	    vis[node] = 1;
	    vector<int> ans;
	    ans.push_back(node);
	    for(auto it : transpose[node]){
	        if(!vis[it])
	            revDfs(it, vis, transpose);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        vector<int> vis(V, 0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, adj, st, vis);
            }
        }
        vector<int> transpose[V];
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                transpose[it].push_back(i);
            }
        }
        int cnt=0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                revDfs(node, vis, transpose);
                cnt++;
            }
        }
        return cnt;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends