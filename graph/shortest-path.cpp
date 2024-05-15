// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
//test case
// 5 6
// 1 2 2
// 2 5 5
// 2 3 4
// 1 4 1
// 4 3 3
// 3 5 1


#include <bits/stdc++.h>
#include "../ctemplate.h"

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    int source = 1;

    vector<pair<int, int>> adj[n+1];

    for(auto edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> ans;
    vector<int> dis(n+1, INT_MAX);
    vector<int> parent(n+1, 0);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    dis[source] = 0;

    //pair<weight, node>;
    set<pair<int, int>> st;
    st.insert({0, source});

    while(!st.empty()) {
        auto top = st.begin();
        int node = top->second;
        int weight = top->first;

        st.erase(st.begin());

        for(auto edge : adj[node]) {
            if(dis[edge.first] > weight + edge.second) {
                st.erase({dis[edge.first], edge.first});
                dis[edge.first] = weight + edge.second;
                parent[edge.first] = node;
                st.insert({dis[edge.first], edge.first});
            }
        }
    }

    if(dis[n] == INT_MAX) {
        return {-1};
    }

    int i = n;
    while(i != source) {
        ans.push_back(i);
        i = parent[i];
    }
    ans.push_back(source);
    ans.push_back(dis[n]);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < 3; ++j)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        edges.push_back(temp);
        mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
        mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
    }

    vector<int> res = shortestPath(n, m, edges);
    int ans = 0;
    for (int i = 2; i < res.size(); i++)
    {
        ans += mp[{res[i], res[i - 1]}];
    }
    if (ans == res[0]) {
    }
    else if (res.size() == 1 && res[0] == -1) {
            ans = res[0];
    }
    else ans = -2;


    cout << ans;

    return 0;
}