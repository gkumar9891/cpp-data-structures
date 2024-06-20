// https://www.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
#include <bits/stdc++.h>
#include "../../ctemplate.h"
vector<vector<int>> dp;
int mod = 1e9+7;
int knapsack(string &s1, string &s2, int n, int m) {
    if(m == -1) {
        return 1;
    }

    if(n == -1) {
        return 0;
    }

    if(dp[n][m] != -1) {
        return dp[n][m];
    }

    int count = 0;
    if(s1[n] == s2[m]) {
        count = knapsack(s1, s2, n-1, m-1) % mod;
    }

    count += knapsack(s1, s2, n-1, m) % mod;


    return dp[n][m] = count % mod;
}

int countWays(string s1, string s2) {
    dp = vector<vector<int>>(s1.length()+1, vector<int>(s2.length()+1, -1));
    return knapsack(s1, s2, s1.length()-1, s2.length()-1);
}

int countWays(string s1, string s2) {
    dp = vector<vector<int>>(s1.length()+1, vector<int>(s2.length()+1, -1));
    return knapsack(s1, s2, s1.length()-1, s2.length()-1);
}

int main() {

    string s1;
    string s2;

    read(s1);
    read(s2);

    write(countWays(s1, s2));

    return 0;
}
