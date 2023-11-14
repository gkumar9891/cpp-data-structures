#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

bool isScramble(string s1, string s2){
    if(s1.length() != s2.length())
        return false;
        
    if(!s1.length() && !s2.length())
        return true;
        
    if(s1.compare(s2) == 0)
        return true;
        
    if(s1.length() <= 1)
        return false;
    
    int n = s1.length();
    
    if(mp.find(s1+" "+s2) != mp.end())
        return mp[s1+" "+s2];
    
    for(int i = 1; i < n; i++) {
        
        string t1 = s1.substr(0, i);
        string t2 = s2.substr(n-i, i);
        string t3 = s1.substr(i, n-i);
        string t4 = s2.substr(0, n-i);
        string t5 = s2.substr(0,i);
        string t6 = s2.substr(i, n-i);
        
        bool case11 = isScramble(t1, t2);
        bool case12 = isScramble(t3, t4);
        bool case21 = isScramble(t1, t5);
        bool case22 = isScramble(t3, t6);
        
        if( case11 && case12 ) {
            return true;   
        }
        
        if( case21 && case22 ) {
            // cout << s1 << " " << s2 << "case12" << endl;
            return true;
        }
    }
    
    return mp[s1+" "+s2] = false;
}

int main() {
    cout << isScramble("coder", "oderc");
}