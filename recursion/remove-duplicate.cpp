#include <iostream>
using namespace std;

string removeDupliate(string s) {
    if(s.length() == 0) {
        return "";
    }

    string rest = removeDupliate(s.substr(1));

    if(s[0] == rest[0]) {
        return rest;
    }

    return (s[0] + rest);
}

int main() {

    cout << removeDupliate("HelloooHH5523");

    return 0;
}