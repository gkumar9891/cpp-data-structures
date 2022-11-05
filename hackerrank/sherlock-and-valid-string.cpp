// https://www.hackerrank.com/challenges/sherlock-and-valid-string/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    unordered_map<char, int> map1;
    unordered_map<int, int> map2;
    
    for(int i = 0; i < s.size(); i++){
        map1[s[i]]++;
        int map1Val = map1[s[i]];
        
        map2[map1Val]++;
        map2[map1Val-1]--; 
    }
    
    int stringLength = s.size();
    int minFreq = 100000; int maxFreq = 0;
    
    
    for(auto it = map2.begin(); it != map2.end(); it++) {
        if(it->first > maxFreq) {
            maxFreq = it->first;
        }
        
        if(minFreq > it->first && it->first != 0 && it->second != 0) {
            minFreq = it->first;
        }
    }
    
    if(minFreq == maxFreq) {
        return "YES";
    }
    
    int total = (map2[minFreq] * minFreq) + (map2[maxFreq] * maxFreq);
    
    if(total == stringLength) {
        if(abs(minFreq - maxFreq) == 1) {
            if(map2[minFreq] == 1 || map2[maxFreq] == 1) {
                return "YES";
                }
        } else if (minFreq == 1 && map2[minFreq] == 1) {
            return "YES";
        }
    }
     
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

