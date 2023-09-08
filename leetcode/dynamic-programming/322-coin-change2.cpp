class Solution {
public:
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

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int val = helper(amount, coins, 0);
        if(val == INT_MAX)
            return -1;

        return val;
    }
};