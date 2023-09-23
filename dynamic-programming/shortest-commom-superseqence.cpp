#include <bits/stdc++.h>
using namespace std;

int LCS(string &x, string &y, int m, int n) {
    if(m == -1 || n == -1)
        return 0;

    if(x[m] == y[n])
        return 1 + LCS(x, y, m-1, n-1);
    else 
        return max(LCS(x, y, m-1, n), LCS(x, y, m, n-1));
}

int main() {
    string x = "geek";
    string y = "eke";

    int count = LCS(x, y, x.length()-1, y.length()-1);
    cout << x.length() + y.length() - count;

    return 0;
}
