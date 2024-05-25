// https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

vector<vector<int>> dp;
int findPalindrome(string &str, int i, int j) {    
    if(i == j || i > j) {
        return 0;
    }
    
    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    if(str[i] == str[j]) {
        return dp[i][j] = findPalindrome(str, i+1, j-1);
    } else {
        return dp[i][j] = min(1+findPalindrome(str, i+1, j), 1+findPalindrome(str, i, j-1));
    }
}
    
int kPalindrome(string str, int n, int k)
{
    dp=vector<vector<int>>(n,vector<int>(n,-1));
    int len = findPalindrome(str, 0, n-1);
    if(len > k) {
        return 0;
    }

    return 1;
}

int main() {

    string str;
    int n, k;
    read(n);
    read(k);
    read(str);

    write(kPalindrome(str, n, k));

    return 0;
}