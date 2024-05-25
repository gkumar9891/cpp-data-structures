// https://leetcode.com/problems/minimum-window-substring/
#include <bits/stdc++.h>
#include "../ctemplate.h"

string minWindow(string s, string t) {
    unordered_map<char, int> mp;
    for(auto c : t) {
        mp[c]++;
    }

    int count = mp.size();

    int i = 0;
    int j = 0;

    int start = 0;
    int end = 0;

    int ans = INT_MAX;
    string ansString = "";

    while(j < s.length()) {
        if(mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if(mp[s[j]] == 0) {
                count--;
            }
        }

        if(count == 0) {
            while(count == 0) {
                if(j-i+1 < ans) {
                    ans = j-i+1;
                    start = i;
                    end = ans;
                }

                if(mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;

                    if(mp[s[i]] == 1) {
                        count++;
                    }
                }
                i++;
            }

            j++;
        } else {
            j++;
        }

    }

    return s.substr(start, end);  
}

int main() {
    string s;
    string t;

    read(s);
    read(t);

    write(minWindow(s, t));

    return 0;
}