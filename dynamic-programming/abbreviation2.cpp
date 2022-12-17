#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

string abbreviation(string a, string b) {
    
    int grid[b.length() + 1][a.length() + 1];
    
    for(int i = 0; i <= b.length(); i++) {
        for(int j = 0; j <= a.length(); j++) {
            grid[i][j] = 0;        
        }
    }
    
    grid[0][0] = 1;
    
    for(int i = 0; i <= b.length(); i++) {
        for(int j = 0; j <= a.length(); j++) {
            if(grid[i][j]) {
                if(toupper(a[j]) == b[i]){
                    grid[i + 1][j + 1] = 1;
                } if(!isupper(a[j])) {
                    grid[i][j+1] = 1;
                }
            }        
        }
    }
    
    for(int i = 0; i <= b.length(); i++) {
        for(int j = 0; j <= a.length(); j++){
            cout << grid[i][j] << " ";
        } cout << endl;
    }

    if(grid[b.length()][a.length()] == 1){
        return "YES";
    } else {
        return "NO";
    }
}

int main() {
    string a = "aabcde";
    string b = "ABCD";

    cout << abbreviation(a, b);
    
    return 0;
}