// https://leetcode.com/problems/longest-substring-without-repeating-characters/
#include <bits/stdc++.h>
#include "../ctemplate.h"

int lengthOfLongestSubstring(string s) {
    int i = 0;
    int j = 0;

    unordered_map<char, int> mp;
    int ans = 0;

    while(j < s.length()) {
        mp[s[j]]++;

        if(mp.size() ==  j-i+1) {
            ans = max(ans, j-i+1);
        } else if (mp.size() < j-i+1) {
            while(mp.size() < j-i+1) {
                mp[s[i]]--;
                if(mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }
        }

        j++;
    }

    return ans;
}

int main() {

    string s;
    read(s);

    write(lengthOfLongestSubstring(s));

    return 0;
}