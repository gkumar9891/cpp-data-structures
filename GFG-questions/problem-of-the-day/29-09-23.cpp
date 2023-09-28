#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &grid, pair<int, int> coord, vector<vector<int>> &track) {
    int i = coord.first;
    int j = coord.second;
    
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] == 0 || track[i][j] == 0) {
        return;
    }
    
    if(grid[i][j] == 1) {
        grid[i][j] = 0;
        track[i][j] = 0;
    }
    
    DFS(grid, {i+1, j}, track);
    DFS(grid, {i, j+1}, track);
    DFS(grid, {i-1, j}, track);
    DFS(grid, {i, j-1}, track);
}

int numberOfEnclaves(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    vector<vector<int>> track(grid.size(), vector<int>(grid[0].size(), 1));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j] == 1 && grid[i][j] == 1 && i == 0 || j == 0 || i == grid.size()-1 || j == grid[i].size()-1)
                q.push({i,j});  
        }
    }
    
    while(!q.empty()) {
        DFS(grid, q.front(), track);
        q.pop();
    }
    
    int count = 0;
    
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++) {
            if(grid[i][j])
                count++;
        }
    }
    
    return count;
}

int main() {

    vector<vector<int>> grid = {{0, 0, 0, 0},
                                {1, 0, 1, 0},
                                {0, 1, 1, 0},
                                {0, 0, 0, 0}};


    cout << numberOfEnclaves(grid);       

    return 0;
}