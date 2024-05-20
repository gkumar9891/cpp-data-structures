// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

void toposort(int node, vector<vector<int>>& adj, stack<int> &stk, vector<int> &vis) {
    vis[node]++;

    for(auto adjNode : adj[node]) {
        if(!vis[adjNode]) {
            toposort(adjNode, adj, stk, vis);
        }
    }

    stk.push(node);
}

void dfs(int node, vector<vector<int>> &graph, vector<int> &track) {
    track[node]++;

    for(auto n : graph[node]) {
        if(!track[n])
            dfs(n, graph, track);
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    stack<int> stk;
    vector<int> vis(V, 0);
    //toplogical sort
    for(int i = 0; i < V; i++) {
        if(!vis[i])
            toposort(i, adj, stk, vis);
    }

    vector<vector<int>> tgraph(V);
    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            tgraph[adj[i][j]].push_back(i);
        }
    }

    vector<int> track(V, 0);
    int count  = 0;
    while(!stk.empty()) {
        int top = stk.top();
        stk.pop();

        if(!track[top]) {
            dfs(top, tgraph, track);
            count++;
        }
    }

    return count;
}

int main() {
    int V, E;
    read(V);
    read(E);
    vector<vector<int>> adj(V);

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    write(kosaraju(V, adj));


    return 0;
}
