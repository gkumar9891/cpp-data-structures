#include <bits/stdc++.h>
using namespace std;

int t[101][101];

bool isPalindrome(string &s, int i, int j) {
  while(i < j) {
      if(s[i] != s[j])
        return 0;
      
      i++;
      j--;
  }

  return 1;
}

int MCM(string &s, int i, int j) {
    if(i>=j)
        return 0;

    if(isPalindrome(s, i, j))
        return 0;

    if(t[i][j] != -1)
        return t[i][j];

    int ans = INT_MAX;
    for(int k = i; k < j; k++) {
        int left = t[i][k] != -1 ? t[i][k] : MCM(s, i, k);
        int right = t[k+1][j] != -1 ? t[k+1][j] : MCM(s, k+1, j);
        int tempAns = left + right + 1;
        ans = min(tempAns, ans);
    }

    return t[i][j] = ans;
}

int main() {
    string s = "nitik";
    memset(t, -1, sizeof(t));

    cout << MCM(s, 0, s.length()-1);

    return 0;
}