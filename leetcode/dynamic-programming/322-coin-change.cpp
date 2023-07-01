#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }

        if(amount < 0) {
            return INT_MAX - 99;
        }

        int sum = INT_MAX;

        for(int i = 0; i < coins.size(); i++) {
            sum = min(sum, 1 + coinChange(coins, amount - coins[i]));
        }

        return sum;
}

int main() {

    vector<int> coins({1, 2, 5});
    int amount = 11;

    cout << coinChange(coins, amount);

    return 0;
}