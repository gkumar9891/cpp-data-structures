// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int getMin(vector<int> &key, vector<int> &mst) {
    int sum = INT_MAX;
    int index = 0;

    for(int i = 0; i < key.size(); i++) {
        if(key[i] < sum && !mst[i]) {
            sum = key[i];
            index = i;
        }
    }

    return index;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> key(V, INT_MAX);
    key[0] = 0;
    vector<int> mst(V, 0);
    vector<int> parent(V, -1);
    
    for(int i = 0; i < V; i++) {
        int u = getMin(key, mst);
        mst[u]++;

        for(auto edge : adj[u]) {
            int node = edge[0];
            int weight = edge[1];

            if(!mst[node] && key[node] > weight) {
                key[node] = weight;
                parent[node] = u;
            }
        }
    }

    int sum = 0;
    for(auto el : key) {
        sum += el;
    }

    return sum;
}


int main() {

    int V, E;
    read(V);
    read(E);

    vector<vector<int>> adj[V];

    while(E--) {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> t1, t2;
        t1.push_back(v);
        t1.push_back(w);
        adj[u].push_back(t1);
        t2.push_back(u);
        t2.push_back(w);
        adj[v].push_back(t2);
    }

    write(spanningTree(V, adj));

    return 0;
}