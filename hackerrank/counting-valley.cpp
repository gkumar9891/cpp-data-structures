// https://www.hackerrank.com/challenges/counting-valleys/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {

    int totalNoOfValley, startStep, endStep = 0;
    bool enteringValley, endingValley = false;
    
    for(int i = 0; i < path.length(); i++) {
        
        startStep = endStep;
        
        if( path[i] == 'U') {
            endStep++;
        }
        
        if(path[i] == 'D') {
            endStep--;
        }
        
        if(startStep == 0 && endStep == -1) {
            enteringValley = true;
        }
        
        if(startStep == -1 && endStep == 0) {
            endingValley = true;
        }
        
        if(enteringValley && endingValley) {
            totalNoOfValley++;
            enteringValley = endingValley = false;
        }
    }    
    
    return totalNoOfValley;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

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
