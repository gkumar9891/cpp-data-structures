#include <iostream>
using namespace std;

int main() {


    for(int i = 0; i < 10000; i++) {
        if(i % 2 == 0) {
            cout << "0";
        } else {
            cout << "1";
        }
    }

    return 0;
}