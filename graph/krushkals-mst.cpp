#include<bits/stdc++.h>
#include "../debug.h"
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int vertex) {
    for(int i = 0; i < vertex; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(vector<int> &parent, int node) {
    if(parent[node] == node) {
        return node;
    }

    return findParent(parent, parent[node]);
}

void makeUnion(int u, int v, vector<int> &parent, vector<int> &rank) {
       u = findParent(parent, u);
       v = findParent(parent, v);

       if(rank[u] < rank[v]) {
           parent[u] = v;
       } else if(rank[v] < rank[u]) {
           parent[v] = u;
       } else {
           parent[v] = u;
           rank[u]++;
       }
}

void sortGraph( vector< vector<int> > &graph ) {
    for (int i = 1; i < graph.size(); i++) {
        vector<int> temp = graph[i];
        int current = graph[i][2];

        for(int j = i - 1; j >= 0; j--) {
            if(current < graph[j][2]) {
                graph[j + 1] = graph[j];
                graph[j] = temp;
            }
        }
    }
}


void krushkal(vector<int> &parent, vector<int> &rank, vector< vector<int> > &graph) {
    int minWeight = 0;
    for(int i = 0; i < graph.size(); i++) {
        int u = findParent(parent, graph[i][0]);
        int v = findParent(parent, graph[i][1]);

        if(u != v) {
            minWeight = minWeight + graph[i][2];
            makeUnion(u, v, parent, rank);
        }
    }

    cout << minWeight;
}

int main() {
    int vertex = 7;
    vector<int>parent(vertex);
    vector<int>rank(vertex);

    makeSet(parent, rank, vertex);
    
    vector< vector<int> > graph {
        {1, 2, 2},
        {1, 4, 1},
        {1, 5, 4},
        {2, 3, 3},
        {2, 4, 3},
        {2, 6, 7},
        {3, 6, 8},
        {3, 4, 5},
        {4, 5, 9}
    };

    sortGraph(graph);

    krushkal(parent, rank, graph);

    return 0;
}