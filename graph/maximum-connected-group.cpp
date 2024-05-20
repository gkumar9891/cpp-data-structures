// https://www.geeksforgeeks.org/problems/maximum-connected-group/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int findParent(int node, vector<int> &parent) {
    if(parent[node] == node) {
        return node;
    }

    return findParent(parent[node], parent);
}

void makeUnion(int i, int j, vector<int> &parent, vector<int> &rank, vector<int> &size) {
    int u = findParent(i, parent);
    int v = findParent(j, parent);

    if(u == v) {
        return;
    }

    if(rank[u] < rank[v]) {
        parent[u] = v;
        size[v] += size[u];
    } else if(rank[u] > rank[v]) {
        parent[v] = u;
        size[u] += size[v];
    } else {
        parent[v] = u;
        size[u] += size[v];
        rank[u]++;
    }
}

int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size();
    
    vector<int> size(n*n, 1);
    vector<int> parent(n*n);
    vector<int> rank(n*n);
    
    for(int i = 0; i < n*n; i++) {
        parent[i] = i;
    }
    

    int diry[] = {-1, 1, 0, 0};
    int dirx[] = {0, 0 , -1, 1};

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                int cellU = (i * n) + j;

                for(int k = 0; k < 4; k++) {
                    int r = i + diry[k];
                    int c = j + dirx[k];

                    if(r >= 0 && c >= 0 && r < n && c < n && grid[r][c]) {
                        int cellV = (r * n) + c;
                        
                        int p1 = findParent(cellU, parent);
                        int p2 = findParent(cellV, parent);
                    
                        if(p1 != p2) {
                            makeUnion(p1, p2, parent, rank, size);
                        }
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n*n; i++) {
        ans = max(ans, size[i]);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j] == 0) {
                set<int> st;
                for(int k = 0; k < 4; k++) {
                    int r = i + diry[k];
                    int c = j + dirx[k];

                    if(r >= 0 && c >= 0 && r < n && c < n && grid[r][c]) { 
                        int cellV = (r * n) + c;
                        int p1 = findParent(cellV, parent);
                        st.insert(p1);
                    }
                }

                int sum = 1;
                for(auto el : st) {
                    sum += size[el];
                }

                ans = max(ans, sum);
            }
        }
    }

    return ans;
}

int main() {

    int n;
    read(n);
    vector<vector<int>> grid(n, vector<int>(n));
    read(grid);


    write(MaxConnection(grid));

    return 0;
}
