// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1?
#include <bits/stdc++.h>
#include "../ctemplate.h"

int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
    priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
           greater<pair<int, pair<int, int>>>> pq;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<int>> diff(rows, vector<int>(columns, INT_MAX));
    diff[0][0] = 0;

    //pair<diff, pair<row, col>>
    pq.push({0, {0, 0} });

    while(!pq.empty()) {
        auto top = pq.top();
        int difference = top.first;
        int x = top.second.first;
        int y = top.second.second;

        pq.pop();

        for(int i = 0; i < 4; i++) {
            int row = x + dx[i];
            int col = y + dy[i];

            if(row >= 0 && col >= 0 && row < rows && col < columns && diff[row][col] > max(difference, abs(heights[x][y] - heights[row][col])) ) {
                diff[row][col] = max(difference, abs(heights[x][y] - heights[row][col]));
                pq.push({diff[row][col], {row, col}});
            }
        }
    }

    return diff[rows-1][columns-1];
}

int main() {
    int r;
    int c;

    read(r);
    read(c);
    vector<vector<int>> height(r, vector<int>(c));
    read(height);

    write(MinimumEffort(r, c, height));

    return 0;
}