// https://www.geeksforgeeks.org/problems/maximum-stone-removal-1662179442/1

#include <bits/stdc++.h>
#include "../ctemplate.h"
using namespace std;

class Solution {
public:
int findParent(int i, vector<int> &parent) {
    if(parent[i] == i) {
        return i;
    }
    return findParent(parent[i], parent);
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

int maxRemove(vector<vector<int>>& stones, int n) {
    int maxRow = 0;
    int maxCol = 0;
    for(auto stone : stones) {
        maxRow = max(maxRow, stone[0]);
        maxCol = max(maxCol, stone[1]);
    }
    
    vector<int> parent(maxRow+maxCol+2);
    for(int i = 0; i < maxRow+maxCol+2; i++) {
        parent[i] = i;
    }
    
    vector<int> rank(maxRow+maxCol+2, 0);
    unordered_map<int, int> mp;
    for(auto stone : stones) {
        int row = stone[0];
        int col = stone[1] + maxRow + 1;
        
        makeUnion(row, col, parent, rank);
        mp[row] = 1;
        mp[col] = 1;
    }
    
    int count = 0;
    for(auto it : mp) {
        if(findParent(it.first, parent) == it.first) {
            count++;
        }
    }
    
    return n - count;
}

};



// class DisjointSet {
//     vector<int> rank, parent, size;
// public:
//     DisjointSet(int n) {
//         rank.resize(n + 1, 0);
//         parent.resize(n + 1);
//         size.resize(n + 1);
//         for (int i = 0; i <= n; i++) {
//             parent[i] = i;
//             size[i] = 1;
//         }
//     }

//     int findUPar(int node) {
//         if (node == parent[node])
//             return node;
//         return parent[node] = findUPar(parent[node]);
//     }

//     void unionByRank(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (rank[ulp_u] < rank[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//         }
//         else if (rank[ulp_v] < rank[ulp_u]) {
//             parent[ulp_v] = ulp_u;
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             rank[ulp_u]++;
//         }
//     }

//     void unionBySize(int u, int v) {
//         int ulp_u = findUPar(u);
//         int ulp_v = findUPar(v);
//         if (ulp_u == ulp_v) return;
//         if (size[ulp_u] < size[ulp_v]) {
//             parent[ulp_u] = ulp_v;
//             size[ulp_v] += size[ulp_u];
//         }
//         else {
//             parent[ulp_v] = ulp_u;
//             size[ulp_u] += size[ulp_v];
//         }
//     }
// };
// class Solution {
// public:
//     int maxRemove(vector<vector<int>>& stones, int n) {
//         int maxRow = 0;
//         int maxCol = 0;
//         for (auto it : stones) {
//             maxRow = max(maxRow, it[0]);
//             maxCol = max(maxCol, it[1]);
//         }
//         DisjointSet ds(maxRow + maxCol + 1);
//         unordered_map<int, int> stoneNodes;
//         for (auto it : stones) {
//             int nodeRow = it[0];
//             int nodeCol = it[1] + maxRow + 1;
//             ds.unionBySize(nodeRow, nodeCol);
//             stoneNodes[nodeRow] = 1;
//             stoneNodes[nodeCol] = 1;
//         }

//         int cnt = 0;
//         for (auto it : stoneNodes) {
//             if (ds.findUPar(it.first) == it.first) {
//                 cnt++;
//             }
//         }
//         return n - cnt;
//     }
// };

int main() {

    int n;
    read(n);
    vector<vector<int>> stones(n, vector<int>(2));
    read(stones);
    
    Solution obj;
    int ans = obj.maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;
    return 0;
}