// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
#include <bits/stdc++.h>
#include "../debug.h"
#include "../ctemplate.h"

vector<int> stak;

void toposort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node]++;

    for (auto n : adj[node])
    {
        if (!vis[n.first])
            toposort(n.first, adj, vis, st);
    }

    st.push(node);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    vector<int> vis(N, 0);
    stack<int> st;
    vector<pair<int, int>> adj[N];

    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    toposort(0, adj, vis, st);

    vector<int> dis(N, INT_MAX);
    dis[0] = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        for (auto n : adj[top])
        {
            dis[n.first] = min(dis[n.first], dis[top] + n.second);
        }
    }

    for (auto &d : dis)
        if (d == INT_MAX)
            d = -1;

    return dis;
}

int main()
{
    int N, M;
    read(N);
    read(M);
    vector<vector<int>> edges(M, vector<int>(3));
    read(edges);

    write(shortestPath(N, M, edges));

    return 0;
}