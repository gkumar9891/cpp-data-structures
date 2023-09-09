class Solution {
public:
    int memo[1001][1001];
    int LCS(string &x, string &y, int m, int n) {
        if(n == -1 || m == -1)
            return 0;

        if(memo[m][n] != -1)
            return memo[m][n];

        if(x[m] == y[n])
            return memo[m][n] = 1 + LCS(x, y, m-1, n-1);
        else
            return memo[m][n] = max(LCS(x, y, m, n-1), LCS(x, y, m-1, n));
    }
    int longestCommonSubsequence(string x, string y) {
        memset(memo, -1, sizeof(memo));

        return LCS(x, y, x.length() - 1, y.length() - 1);
    }
};