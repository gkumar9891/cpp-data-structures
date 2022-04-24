#include <iostream>
using namespace std;

string generateString(string s){
    if(s.length() == 0) {
        return "";
    }

    string temp = "";

    generateString(s.substr(1));
    cotu << temp + s[0];
    generateString()

    return s;

}

int main() {


    generateString("ABC"); 
    return 0;
}