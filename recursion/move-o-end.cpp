#include <iostream>
using namespace std;

string moveOEnd(string s) {
    if(s.length() == 0) {
        return "";
    }

    string rest = moveOEnd(s.substr(1));

    if(s[0] != 'o') {
        return (s[0] + rest);
    }

    return (rest + 'o');
}

int main() {
git
    string s = "aoobdocefohio";
    cout << moveOEnd(s);

    return 0;
}