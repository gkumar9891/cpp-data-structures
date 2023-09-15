#include <bits/stdc++.h>
using namespace std;

int LCS(string &a, string &b, int m, int n) {
    if(m == -1 || n == -1)
        return 0;

    if(a[m] == b[n])
        return 1 + LCS(a, b, m-1, n-1);
    else {
        return max(LCS(a,b,m-1,n), LCS(a,b,m,n-1));
    }
}

int main() {
    string a = "heap";
    string b = "pea";

    int count = LCS(a, b, a.length()-1, b.length()-1);

    cout << "insert" << " -- " << b.length() - count << endl;
    cout << "delete" << " -- " << a.length() - count;

    return 0;
}