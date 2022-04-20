#include <iostream>
using namespace std;

void separateString(string s, string ans){

    if(s.length() == 0) {
        cout << ans << endl;
        return;
    }

    int code = s[0];

    separateString(s.substr(1), ans);
    separateString(s.substr(1), ans + s[0]);
    separateString(s.substr(1), ans + to_string(code));
}


int main() {

    separateString("AB", "");

    return 0;
}