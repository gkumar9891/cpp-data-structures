#include <iostream>
using namespace std;

void reverseString(string s) {
    if(s.length() == 0){
        return;
    }

    string substring = s.substr(1);
    reverseString(substring);
    cout << s[0];
}

int main() {

    string s = "helloworld";

    reverseString("helloworld");
    return 0;
}