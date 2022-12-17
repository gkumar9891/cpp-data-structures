#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'substrCount' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING s
 */

long substrCount(int n, string s) {
 long count = 0;
 int left[n] = {0};
 int right[n] = {0};
 
 left[0] = 1;
 right[n - 1] = 1;
 
 for(int i = 1; i < n; i++) {
     if(s[i] == s[i - 1]){
         left[i] = left[i - 1] + 1;
     } else {
         left[i]++;
     }
 }
 
 for(int i = n - 2; i >= 0; i--) {
     if(s[i] == s[i + 1]){
         right[i] = right[i + 1] + 1;
     } else {
         right[i]++;
     }
 }
 
 
//  for(int i = 0; i < n; i++){
//      cout << right[i] << " ";
//  }
 
 for(int i = 0; i < n; i++){
    count++;
    
    if(i>0 && i < n-1){
        if(s[i] != s[i-1] && s[i-1] == s[i+1] ){
            count = count + min(left[i-1], right[i+1]);
        } else if(s[i-1] == s[i]) {
            count = count + left[i] - 1;
        }
    }
    
    if(i == n-1 && s[i] == s[i-1]){
        count = count + left[i] - 1;
    }  
 }
 
 cout << count;
 
 return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

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
