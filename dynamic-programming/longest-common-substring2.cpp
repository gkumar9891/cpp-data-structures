#include <bits/stdc++.h>
using namespace std;

int t[1001][1001];
int ans;
int LCS(vector<int> &x, vector<int>& y, int m, int n) {
    if(m == -1 || n == -1)
        return 0;

    if(t[m][n] != -1)
        return t[m][n];        

    if(x[m] == y[n]) {
        t[m][n] = 1 + LCS(x, y, m-1, n-1);
    } else {
        t[m][n] = 0;
    }

    LCS(x, y, m, n-1);
    LCS(x, y, m-1, n);
    ans = max(ans, t[m][n]);
    return t[m][n];
}

int main() {
    // string x = "GeeksforGeeks";
    // string y = "GeeksQuiz";

    vector<int> x = {0,1,1,1,1};
    vector<int> y = {1,0,1,0,1};

    memset(t, -1, sizeof(t));
    ans = 0;
    LCS(x, y, x.size() - 1, y.size() - 1);
    cout << ans;

    return 0;
}