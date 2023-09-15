#include <bits/stdc++.h>
using namespace std;

int repeatingSeq(string a, string b, int m, int n) {
    if(m == -1 || n == -1)
        return 0;
    
    if(a[m] == b[n] && m != n)
        return 1 + repeatingSeq(a, b, m-1, n-1);

    return max(repeatingSeq(a, b, m-1,n), repeatingSeq(a, b, m, n-1));
}

int main() {
    string a = "AABEBCDD";
    cout << repeatingSeq(a, a, a.length()-1, a.length()-1);

    return 0;
}