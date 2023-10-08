#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;

int MCM(string &s, int i, int j, bool isTrue) {
    if(i > j)
        return 0;
    
    if(i == j) {
        if(isTrue)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }

    string ansKey = to_string(i)+to_string(j)+to_string(isTrue);

    if(mp.find(ansKey) != mp.end()) {
        return mp[ansKey];
    }


    int ans = 0;

    for(int k = i+1; k < j; k += 2) {
        int lT = MCM(s, i, k-1, true);
        int lF = MCM(s, i, k-1, false);
        int rT = MCM(s, k+1, j, true);
        int rF = MCM(s, k+1, j, false);

        if(s[k] == '&') {
            if(isTrue)
                ans += (lT * rT);
            else
                ans += (lT * rF) + (lF * rF) + (lF * rT);  
        
        } else if(s[k] == '|') {
            if(isTrue)
                ans +=  (lT * rF) + (lT * rT) + (lF * rT);
            else
                ans += (lF * rF);
       
        } else if(s[k] == '^') {
            if(isTrue)
                ans += (lT * rF) + (lF * rT);
            else
                ans += (lT * rT) + (lF * rF);
        }
    }

    return mp[ansKey] = ans;
}

int main() {
    string s = "T|F&T^F";
    mp.clear();
    cout << MCM(s, 0, s.length()-1, true);

    return 0;
}