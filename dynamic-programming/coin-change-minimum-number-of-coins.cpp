#include <bits/stdc++.h>
using namespace std;

int t[13][1000001];
int helper(int amount, vector<int> &coins, int index) {
    if(index == coins.size())
        return INT_MAX;
    
    if(amount < 0)
        return INT_MAX;

        if(amount == 0)
        return 0;

    if(t[index][amount] != -1)
        return t[index][amount];
    
    int take = helper(amount - coins[index], coins, index);
    int notTake = helper(amount, coins, index + 1);

    if(take != INT_MAX) {
        take++;
    }
    
    return t[index][amount] = min(take, notTake);
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    memset(t, -1, sizeof(t));
    int val = helper(amount, coins, 0);
    if(val == INT_MAX)
        val = -1;

    cout << val;


    return 0;
}