#include <bits/stdc++.h>
using namespace std;

int t[3001][5001];

int findTargetSum(int amount, vector<int> &coins, int index, int sum) {
    if(index == coins.size())
        return 0;
    
    if(sum == amount)
        return 1;
    
    if(sum > amount)
        return 0;

    if(t[index][sum] != -1)
        return t[index][sum];
    
    return t[index][sum] = findTargetSum(amount, coins, index, sum + coins[index]) +
    findTargetSum(amount, coins, index + 1, sum);
}

int main() {
    memset(t, -1, sizeof(t));
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    cout << findTargetSum(amount, coins, 0, 0);

    return 0;
}