class Solution {
public:
    int t[3001][5001];
    int helper(int amount, vector<int> &coins, int index, int sum) {
        if(index == coins.size())
            return 0;
        
        if(sum == amount)
            return 1;
        
        if(sum > amount)
            return 0;

        if(t[index][sum] != -1)
            return t[index][sum];
        
        return t[index][sum] = helper(amount, coins, index, sum + coins[index]) +
        helper(amount, coins, index + 1, sum);
    }

    int change(int amount, vector<int>& coins) {
        memset(t, -1, sizeof(t));
        return helper(amount, coins, 0, 0);
    }
};