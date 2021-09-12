#include <iostream>
using namespace std;

int getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

int setBit(int n, int pos) {
    return (n | (1 << pos));
}

void uniqueValue(int a[]){
    int sum = 0;

    for(int i = 0; i < 7; i++){
        sum = sum ^ a[i];
    }

    cout << sum;
}

int main() {

    cout << getBit(5, 0) << " ";
    cout << setBit(5, 1) << " ";

    int a[] = {1,4,3,4,1,3,2};

    uniqueValue(a);


    return 0;
};