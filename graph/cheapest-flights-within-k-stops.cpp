// https://www.geeksforgeeks.org/problems/cheapest-flights-within-k-stops/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  queue<pair<int, pair<int, int>>> q;
  vector<pair<int, int>> adj[n];
  for(auto flight : flights) {
    adj[flight[0]].push_back({flight[1], flight[2]});
  };

  q.push({0, {src, 0}});

  while(!q.empty()) {
    auto f = q.front();
    int stop = f.first;
    int node = f.second.first;
    int cost = f.second.second;
    q.pop();

    if(node == dst || stop > k) {
        continue;
    }

    for(auto edge : adj[node]) {
        int adjNode = edge.first;
        int edW = edge.second;

        if(cost + edW < dist[adjNode] && stop <= k) {
            dist[adjNode] = cost + edW;
            q.push({stop+1, {adjNode, dist[adjNode]}});
        }
    }
  }

  if(dist[dst] == INT_MAX) {
    return -1;
  }

  return dist[dst];

}

int main() {
    int n;
    read(n);
    int e;
    read(e);
    vector<vector<int>> flights(e, vector<int>(3));
    read(flights);
    int src;
    int dest;
    int k;
    read(src);
    read(dest);
    read(k);
    
    write(CheapestFLight(n, flights, src, dest, k));
    return 0;
}