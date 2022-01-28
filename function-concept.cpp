#include <iostream>
using namespace std;

/** In function overloading there are functions with same name with different parameter.
    in this which function will be called that depends on the parameters
**/

/** example of function overloading **/
int sum(int a, int b, int c){
    int sum = a + b + c;
    return sum;
}

int sum(int a, int b) {
    int sum = a + b;
    return sum;
}

/** end of example of function overloading **/





int main() {
    // int sumVal = sum(3, 5);
    int sumVal = sum(3, 5, 7);

    cout << sumVal;

    return 0;
}