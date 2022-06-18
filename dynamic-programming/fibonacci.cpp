#include <iostream>
#include <map>
using namespace std;

int fibonacci(int n, map<long, long> &hash) {
    if( hash.count(n) != 0) return hash[n];

    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return 1;
    }

    hash[n] = fibonacci(n - 1, hash) + fibonacci(n - 2, hash);
    return hash[n];
}


int main() {

   map<long, long> hash;

    cout << fibonacci(9, hash) << endl ;
    cout << fibonacci(12, hash)  << endl;
    cout << fibonacci(30, hash) << endl;
    cout << fibonacci(45, hash) << endl;

    return 0;
}