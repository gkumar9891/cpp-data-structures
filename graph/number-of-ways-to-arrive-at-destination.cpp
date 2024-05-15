// https://www.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int countPaths(int n, vector<vector<int>>& roads) {
    vector<long long> ways(n, 0);
    ways[0] = 1;
    vector<long long> dist(n, 1e18);
    vector<pair<int, int>> adj[n];
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    
    int mod = (int)(1e9 + 7);

    for(auto road : roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], road[2]});
    }

    while(!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            long long edW = it.second;

            if(dist[adjNode] > dis + edW) {
                dist[adjNode] = dis + edW;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            } else if(dist[adjNode] == dis+edW) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1] % mod;
}
int main() {
    int n, m;
    read(n);
    read(m);

    vector<vector<int>> edges(m, vector<int>(3));
    read(edges);

    write(countPaths(n, edges));

    return 0;
}