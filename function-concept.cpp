#include <iostream>
using namespace std;

int sum(int a, int b, int c){
    int sum = a + b + c;
    return sum;
}

int sum(int a, int b) {
    int sum = a + b;
    return sum;
}



int main() {

    // int sumVal = sum(3, 5);
    int sumVal = sum(3, 5, 7);

    cout << sumVal;

    return 0;
}