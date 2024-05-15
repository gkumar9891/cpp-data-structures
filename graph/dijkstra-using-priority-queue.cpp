// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <bits/stdc++.h>
#include "../ctemplate.h"

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis(V, INT_MAX);
    dis[S] = 0;

    pq.push({0, S});

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        pq.pop();

        for (auto el : adj[top.second])
        {
            if (dis[el[0]] > top.first + el[1])
            {
                dis[el[0]] = top.first + el[1];
                pq.push({dis[el[0]], el[0]});
            }
        }
    }

    return dis;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
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
        int S;
        cin >> S;
        vector<int> res = dijkstra(V, adj, S);
        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}