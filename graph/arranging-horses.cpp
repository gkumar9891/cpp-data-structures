#include <bits/stdc++.h>
#include "../ctemplate.h"

vector<int> arrangingHorses(int n, int m, vector<vector<int>> &data) {
    vector<int> adj[n];
    vector<int> indegree(n, 0);

    for(auto el : data) {
        adj[el[1]].push_back(el[0]);
        indegree[el[0]]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i <n; i++) {
        if(indegree[i] == 0) {
            pq.push({i});
        }
    } 

    vector<int> ans;
    while(!pq.empty()) {
        int node = pq.top();
        pq.pop();
        ans.push_back(node);
        for(auto child : adj[node]) {
            indegree[child]--;
            if(indegree[child] == 0) {
                pq.push(child);
            }
        }
    }
    return ans;
}

int main() {

    int v;
    int m;
    read(v);
    read(m);
    vector<vector<int>> data(m, vector<int>(2));
    read(data);

    write(arrangingHorses(v, m, data));

    return 0;
}