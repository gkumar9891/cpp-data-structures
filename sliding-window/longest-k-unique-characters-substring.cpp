// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int longestKSubstr(string s, int k) {
    int i = 0;
    int j = 0;

    int ans = 0;

    unordered_map<char, int> mp;
    int count = 0;
    

    while(j < s.length()) {
        mp[s[j]]++;
        if(mp[s[j]] == 1) {
            count++;
        }

        if(count == k) {
            ans = max(ans, j-i+1);
            j++;
        } else if(count > k) {
            while(count != k) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) {
                    count--;
                }
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        } else {
            j++;
        }
    }

    return ans == 0 ? -1 : ans;
}

int main() {
    string s;
    int k;

    read(s);
    read(k);

    write(longestKSubstr(s, k));

    return 0;
}

