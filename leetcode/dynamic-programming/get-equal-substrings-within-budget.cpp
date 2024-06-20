// https://leetcode.com/problems/get-equal-substrings-within-budget/?envType=daily-question&envId=2024-05-28
#include <bits/stdc++.h>
#include "../../ctemplate.h"

int equalSubstring(string s, string t, int maxCost) {
    int i = 0;
    int j = 0;

    int ans = 0;

    while(j < s.length()) {
        if(abs(s[j] - t[j]) <= maxCost) {
            maxCost -= abs(s[j] - t[j]);
            ans = max(ans, j-i+1);
            j++;
        } else {
            while(maxCost < abs(s[j] - t[j])) {
                maxCost += abs(s[i] - t[i]);
                i++;
            }

            maxCost -= abs(s[j] - t[j]);
            j++;
        }
    }

    return ans;
}

int main() {
    string s;
    string t;
    int maxCost;

    read(s);
    read(t);
    read(maxCost);
    write(equalSubstring(s, t, maxCost));

    return 0;
}