// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int search(string pat, string txt) {
    unordered_map<char, int> mp;
    for(int i = 0; i < txt.length(); i++) {
        mp[txt[i]]++;
    }
    
    int k = txt.length();
    
    int count = mp.size();
    int ans = 0;
    
    int i = 0;
    int j = 0;
    
    while(j < pat.length()) {
    if(mp.find(pat[j]) != mp.end()) {
        mp[pat[j]]--;
        
        if(mp[pat[j]] == 0) {
            count--;
        }
    }
    
    if(j-i+1 == k) {
        if(count == 0) {
            ans++;
        }
        
        if(mp.find(pat[i]) != mp.end()) {
            mp[pat[i]]++;
            if(mp[pat[i]] == 1) {
            count++;    
            }
        }
        
        i++;
        j++;
        
    } else if(j-i+1 < k) {
        j++;
    }
    }
    
    return ans;
}

int main() {
    string pat, txt;
    read(pat);
    read(txt);
    write(search(txt, pat));
    return 0;
}