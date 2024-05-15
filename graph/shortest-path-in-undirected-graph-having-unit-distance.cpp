// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //pair<node, dist>
    queue<pair<int, int>> q;
    vector<int> adj[N];
    
    //creating adjacency list
    for(auto e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(N, INT_MAX);
    dist[src] = 0;

    q.push({src, 0});
    while(!q.empty()) {
        pair<int, int> n = q.front();
        q.pop();

        for(auto el : adj[n.first]) {
            if(dist[el] > dist[n.first] + 1) {
                dist[el] = dist[n.first] + 1;
                q.push({el, dist[el]});
            }
        }
    }

    for(auto &el : dist) {
        if(el == INT_MAX)
            el = -1;
    }

    return dist;
}

int main() {
    int N, M;
    int src;
    read(N);
    read(M);

    vector<vector<int>> edges(M, vector<int>(2));
    
    read(edges);
    read(src);
    
    write(shortestPath(edges, N, M, src));
    return 0;
}