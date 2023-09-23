#include <bits/stdc++.h>
using namespace std;

string findSequence(string& s1, string& s2, int i1, int i2, unordered_map<string, string> &memo) {
    if (i1 >= s1.length()) return s2.substr(i2);
    if (i2 >= s2.length()) return s1.substr(i1);
    const string memoKey = to_string(i1) + "," + to_string(i2);
    if (memo.find(memoKey) != memo.end()) return memo[memoKey];
    if (s1[i1] == s2[i2]) return memo[memoKey] = s1[i1] + findSequence(s1, s2, i1 + 1, i2 + 1, memo); // same char, use either
    const string useS1 = s1[i1] + findSequence(s1, s2, i1 + 1, i2, memo); // try use s1's char
    const string useS2 = s2[i2] + findSequence(s1, s2, i1, i2 + 1, memo); // try use s2's char
    return memo[memoKey] = useS1.length() < useS2.length() ? useS1 : useS2;
}

string shortestCommonSupersequence(string s1, string s2) {
        unordered_map<string, string> memo;
        return findSequence(s1, s2, 0, 0, memo);
}

int main() {
    cout << shortestCommonSupersequence("acbef", "abcdaf");

    return 0;
}