#include <bits/stdc++.h>
using namespace std;

pair<int, string> LCS(string &a, string &b, int m, int n, int index, string str) {
    if(m == -1 || n == -1)
        return {0, str};

    if(a[m] == b[n]) {

        pair<int, string> val = LCS(a,b,m-1,n-1,index, a[m]+str);
        return {val.first+1, val.second};

    } else {
        
        pair<int, string> val1 = LCS(a,b,m-1,n,index+1, str);
        pair<int, string> val2 = LCS(a,b,m,n-1,index+1, str);

        if(val1.first > val2.first)
            return val1;

        return val2;
    }
}


int main() {
    string a = "acbdf";
    string b = "abcdaf";

    pair<int, string> ans = LCS(a, b, a.length()-1, b.length()-1, 0, "");
    cout << ans.first << " " << ans.second;
    
    return 0;
}