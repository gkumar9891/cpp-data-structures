// https://www.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1
// 5/28/2024

#include <bits/stdc++.h>
#include "../../ctemplate.h"

vector<vector<int>> dp;
int findCost(int i, int w, vector<int> &cost) {
    if(w == 0) {
        return 0;
    }
    
    if(i == cost.size() || w < 0) {
        return INT_MAX;
    }
    
    if(dp[i][w] != -1) {
        return dp[i][w];
    }
    
    int x = INT_MAX, y;
    
    y = findCost(i+1, w, cost);
    
    if(cost[i] != -1) {
        x = findCost(i, w-(i+1), cost);   
    }
    
    if(x != INT_MAX) {
        x += cost[i];
    }
    
    return dp[i][w] = min(x, y);
}
    
int minimumCost(int n, int w, vector<int> &cost) {
    // code here

    dp = vector<vector<int>>(n+1, vector<int>(w+1, -1));

    int x = findCost(0, w, cost);
    if(x == INT_MAX) {
        return -1;
    }
    
    return x;
}

int main() {

    int n, w;
    read(n);
    read(w);
    vector<int> cost(n);
    read(cost);

    write(minimumCost(n, w, cost));

    return 0;
}