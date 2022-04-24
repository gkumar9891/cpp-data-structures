#include <iostream>
using namespace std;

void dec(int n) {
    if(n == 0) {
        return;
    }
    cout << n << endl;
    dec(n-1);
}

void asc(double n) {
    if(n == 1){
        cout << n << endl;
        return;
    }
    asc(n - 1);
    cout << n << endl;
}

int main() {

    double n;
    cin >> n;
    asc(n);

    return 0;
}