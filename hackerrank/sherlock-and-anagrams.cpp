#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int findAnagram( string s, char target, int total, int j) {
     if(s.length() == 0) {
         return total;
     }
     
     for(int i = j; i < s.length(); i++) {
         if(s[i] == target) {
             total++;
         }
     }
        
     return findAnagram(s.substr(1), s[0], total, j);
}



int sherlockAndAnagrams(string s) {
    unordered_map<string, int> matches;
    int anagram_cnt = 0;
    for (unsigned base_idx = 0; base_idx < s.size(); base_idx++)
    {
        for (unsigned offset_idx = base_idx; offset_idx < s.size(); offset_idx++)
        {
            auto substr = s.substr(base_idx, offset_idx - base_idx + 1);
            cout << substr << " ";
            sort(substr.begin(), substr.end());
            cout << substr << " ";
            anagram_cnt += matches[substr]++;
            cout << anagram_cnt << endl;
        }
    }
    return anagram_cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
