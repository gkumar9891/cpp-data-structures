#include <iostream>
#include <algorithm>
using namespace std;

string abbreviation(string &a, string &b){
    int width;
    int height;

    if(a.length() >= b.length()){
        width = a.length();
        height = b.length();
    }

    transform(a.begin(), a.end(), a.begin(), ::toupper);

    int grid[height + 1][width + 1];

    for(int i = 0; i <= height; i++) {
        grid[i][0] = 0;
    }

    for(int i = 0; i <= width; i++) {
        grid[0][i] = 0;
    }

    for(int i = 1; i <= height; i++){
        for(int j = 1; j <= width; j++) {
            if(b[i-1] == a[j-1]) {
                grid[i][j] = 1 + grid[i-1][j-1];
            } else {
                grid[i][j] = max(grid[i][j-1], grid[i-1][j]);
            }
        }
    }

    string commonString = "";

    int j=width;
    int i=height;

    while(i != 0 || j != 0) {
        if(grid[i][j-1] == grid[i][j]){
            j--;
        } else if (grid[i-1][j] == grid[i][j]) {
            i--;
        } else {
            commonString.push_back(b[i-1]);
            i--;
            j--;
        }
    }
    reverse(commonString.begin(), commonString.end());

    if(commonString == b) {
        return "YES";
    } else {
        return "NO";
    }
}

int main() {

    string a = "AbcDe";
    string b = "AFDE";

    cout << abbreviation(a,b);   

    return 0;
}