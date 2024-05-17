// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<pair<int, int>> adj[n];
    for(auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }
    
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    
    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
        
        queue<pair<int, int>> q;
        q.push({0, i});
        
        while(!q.empty()) {
            auto f = q.front();
            int edW = f.first;
            int node = f.second;

            q.pop();

            for(auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if(dist[i][v] > edW + wt) {
                    dist[i][v] = edW + wt; 
                    q.push({dist[i][v], v});
                }
            }
        }
    }

    int maxCity = INT_MAX;
    int cityNo = -1;

    for(int i = 0; i < n; i++) {
        int tempCity = 0;
        for(int j = 0; j < n; j++) {
            if(dist[i][j] <= distanceThreshold) {
                tempCity++;
            }
        }

        if(tempCity <= maxCity) {
            maxCity = tempCity;
            cityNo = i;
        }
    }

    return cityNo;
}

int main() {
    int n, m;
    read(n);
    read(m);
    vector<vector<int>> edges(m, vector<int>(3));
    read(edges);
    int t;
    read(t);

    write(findCity(n, m, edges, t));
    return 0;
}