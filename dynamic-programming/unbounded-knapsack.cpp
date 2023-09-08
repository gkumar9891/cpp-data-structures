#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int unboundedKnapsack(vector<int> &length, vector<int> &price, int n, int index) {    
    if(n == 0 || index < 0)
        return 0;

    if(dp[n][index] != -1){
        return dp[n][index];
    }

    if(length[index] <= n) {
        return dp[n][index] = max(price[index] + unboundedKnapsack(length, price, n - length[index], index), 
    unboundedKnapsack(length, price, n, index - 1) );    
    } else {
        return dp[n][index] = unboundedKnapsack(length, price, n, index - 1);
    }
}

int main() {
    memset(dp, -1, sizeof(dp));

    int n = 8;
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << unboundedKnapsack(length, price, n, length.size()-1);

    return 0;
}