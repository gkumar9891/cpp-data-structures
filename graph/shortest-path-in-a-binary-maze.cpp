// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include <bits/stdc++.h>
#include "../ctemplate.h"

int findDestination(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> &destination, vector<vector<int>> &track, int count)
{
    int sf = source.first;
    int ss = source.second;

    if (sf == -1 || ss == -1 || sf == grid.size() || ss == grid[0].size() || !grid[sf][ss] || track[sf][ss])
    {
        return INT_MAX;
    }

    if (sf == destination.first && ss == destination.second)
    {
        return count;
    }

    track[sf][ss] = 1;

    int row[] = {-1, 1, 0, 0};
    int col[] = {0, 0, -1, 1};

    int ans = INT_MAX;

    for (int i = 0; i < 4; i++)
    {
        int r = source.first + row[i];
        int c = source.second + col[i];

        ans = min(ans, findDestination(grid, {r, c}, destination, track, count + 1));
    }

    return ans;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination)
{

    // vector<vector<int>> track(grid.size(), vector<int>(grid[0].size(), 0));

    // int ans = findDestination(grid, source, destination, track, 0);

    // return ans == INT_MAX ? -1 : ans;

    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        auto it = q.front();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newr = r + dr[i];
            int newc = c + dc[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc])
            {
                dist[newr][newc] = 1 + dis;
                q.push({1 + dis, {newr, newc}});
            }
        }
    }
    return dist[destination.first][destination.second] == 1e9 ? -1 : dist[destination.first][destination.second];
}

int main()
{

    int r;
    int c;
    read(r);
    read(c);
    vector<vector<int>>(r, vector<int>(c)) grid;
    read(grid);

    pair<int, int> source, destination;
    cin >> source.first >> source.second;
    cin >> destination.first >> destination.second;

    write(shortestPath(grid, source, destination))

        return 0;
}