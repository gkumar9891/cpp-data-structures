#include <iostream>
#include <vector>

using namespace std;

int solve(vector<int>& nums, int index, vector<int> &dp) {
    int amount = 0;
    if(index < nums.size()) {
        amount += nums[index];
    }

    if(index >= nums.size()) {
        return 0;
    }

    if(dp[index] != -1) {
        return dp[index];
    }

    for(int i = index + 2; i < nums.size(); i++) {
        dp[index] = max(dp[index], nums[index] + solve(nums, i, dp));
    }

    return dp[index] < amount ? amount : dp[index];
}

int solveWithTab(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0);

    dp[0] = nums[0];
    for(int i = 1; i < n; i++) {
        int incl = i - 2 >= 0 ? dp[i-2] + nums[i] : 0 + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

int rob(vector<int> nums) {
    // int sum = 0;
    // vector<int> dp(nums.size() + 1, -1);
    // for(int i = 0; i < nums.size(); i++) {
    //     sum = max(sum, solveWithTab(nums, i, dp));
    // }

    // return sum;

    return solveWithTab(nums);
}

int main() {
    cout << rob(vector<int>({1, 2, 3, 1}));
    return 0;
}