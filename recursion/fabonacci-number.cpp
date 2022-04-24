#include <iostream>
using namespace std;

int fabonacciNumber(int n) {
    if( n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    return fabonacciNumber(n - 1) + fabonacciNumber(n - 2); 
}

int main() {

    int n;
    cin >> n;
    cout << fabonacciNumber(n);

    return 0;
}