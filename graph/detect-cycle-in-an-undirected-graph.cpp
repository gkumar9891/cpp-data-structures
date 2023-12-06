// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:    
    bool dfs(int node, int v, vector<int> adj[], set<pair<int,int>> &edges, vector<int> &vis, bool &ans) {
        if(vis[node])
            return true;
        
        
        vis[node]++;
        
        for(auto j : adj[node]) {
            if(edges.find({node, j}) != edges.end() || edges.find({j, node}) != edges.end() )
                continue;
            
            edges.insert({node, j});
            if(dfs(j, v, adj, edges, vis, ans))
                return true;
        }
        
        return false;
    }
    
    bool isCycle(int v, vector<int> adj[]) {
        set<pair<int,int>> edges;
        vector<int> vis(v, 0);
        
        bool ans = false;
        
        for(int i = 0; i < v; i++) {
            if(!vis[i])
                if(dfs(i, v,adj,edges,vis,ans)) {
                    return true;
                }
        }
                
                
        return false;
    }
}