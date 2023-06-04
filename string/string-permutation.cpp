#include <iostream>
#include <string>
using namespace std;

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permute(string &s, int l, int r) {
    int i;

    if(l==r) {
        cout << s << " ";
    }

    for(i = l; i <= r; i++) {
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]);
    }
}

int main() {

    string s = "ABC";
    permute(s, 0, 2);
    
    return 0;
}
