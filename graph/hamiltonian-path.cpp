// https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1

#include <bits/stdc++.h>

bool dfs(int src, vector<int> &vis, vector<int> edges[], int n, int m, int count) {
    if(count == n)
        return true;
    
    vis[src]++;
    for(auto i : edges[src]) {
        if(!vis[i]) {
            if(dfs(i, vis, edges, n, m, count+1)) {
                return true;
            };
        }
        
    }
    vis[src]--;
    
    return false;
}

bool check(int n,int m,vector<vector<int>> edges)
{
    vector<int> adj[n];
    
    for(auto &x:edges){
        adj[x[0]-1].push_back(x[1]-1);
        adj[x[1]-1].push_back(x[0]-1);
    }
    
    vector<int> vis(n, 0);
    
    for(int i = 0; i < n; i++) {
        if(dfs(i, vis, adj, n, m, 1)){
            return true;
        };
    }
    
    
    return false;
}