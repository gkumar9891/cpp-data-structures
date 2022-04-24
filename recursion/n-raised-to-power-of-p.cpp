#include <iostream>
using namespace std;

int power(int base, int p) {

    if(p == 0) {
        return 1;
    }

    return power(base, p - 1) * base;
}

int main() {

    int base, p;
    cin >> base;
    cin >> p;

    cout << power(base, p); 

    return 0;
}