// https://www.geeksforgeeks.org/problems/number-of-provinces/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int findParent(int i, vector<int> &parent) {
    if(parent[i] == i) {
        return i;
    }

    return findParent(parent[i], parent);
}

void makeUnion(int i, int j, vector<int> &parent, vector<int> &rank) {
    int u = findParent(i, parent);
    int v = findParent(j, parent);

    if(u == v)
        return;

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[v] < rank[u]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

int numProvinces(vector<vector<int>> adj, int V) {
    vector<int> parent(V, 0);
    vector<int> rank(V, 0);

    for(int i = 0; i < V; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < V; i++) {
        for(int j = 0; j < adj[i].size(); j++) {
            if(i == j)
                continue;
            if(adj[i][j])
                makeUnion(i, j, parent, rank);
        }
    }

    int sum = 0;
    for(int i = 0; i < V; i++) {
        if(parent[i] == i)
            sum++;
    }

    return sum;
}

int main() {
    int V, x;
    read(V);

    vector<vector<int>> adj;
    for(int i = 0; i < V; i++) {
        vector<int> temp;
        for(int j = 0; j < V; j++) {
            cin >> x;
            temp.push_back(x);
        }
        adj.push_back(temp);
    }

    write(numProvinces(adj, V));

    return 0;
}