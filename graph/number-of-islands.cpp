// https://www.geeksforgeeks.org/problems/number-of-islands/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int findParent(int node, vector<int> &parent) {
    if(parent[node] == node) {
        return node;
    }
    return findParent(parent[node], parent);
} 

void makeUnion(int i, int j, vector<int> &parent, vector<int> &rank) {
    int u = findParent(i, parent);
    int v = findParent(j, parent);

    if(u == v) {
        return;
    }

    if(rank[u] < rank[v]) {
        parent[u] = v;
    } else if(rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    vector<int> parent(n*m);
    unordered_map<int, int> mp;
    vector<int> ans;

    for(int i = 0; i < n*m; i++) {
        parent[i] = i;
    }

    vector<int> rank(n*m, 0);

    int diry[] = {-1, 1, 0, 0};
    int dirx[] = {0, 0, -1, 1};

    int sum = 0;

    for(auto operation : operators) {
        int r = operation[0];
        int c = operation[1];

        int cellU = (m * r) + c;
        
        if(mp[cellU]) {
            ans.push_back(sum);
            continue;
        }

        mp[cellU]++;
        sum++;

        for(int i = 0; i < 4; i++) {
            int row = r + diry[i];
            int col = c + dirx[i];


            if(row >= 0 && col >= 0 && row < n && col < m) {
                int cellV = (m * row) + col;
                if(mp[cellV]) {
                    int p1 = findParent(cellU, parent);
                    int p2 = findParent(cellV, parent);
                    if(p1 != p2) {
                        makeUnion(cellU, cellV, parent, rank);
                        sum--;    
                    }
                }
            }
        }

        ans.push_back(sum);
    }

    return ans;
}

int main() {
    int n, m, k;
    read(n);
    read(m);
    read(k);

    vector<vector<int>> operators(k, vector<int>(2));
    read(operators);

    write(numOfIslands(n, m, operators));

    return 0;
}