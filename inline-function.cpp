// inline function are same line function and macros if there is just only one line of code in function then you can use inline function it actually after comilation replace the inner code
// for example after comilation at line 18 on "result" it will be replaced with "(a > b) ? a : b"
// it actually used to save function call

#include <iostream>
using namespace std;

inline int maxVal(int& a, int b) {
    return (a > b) ? a : b;
}

int main() {

   int a = 5;
   int b = 10;
   int result = maxVal(a, b);

    cout << "max value is between " << a << " and " << b << " " << result ;
    return 0;
}