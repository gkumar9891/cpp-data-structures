//macros are used to increase efficiency of program
// to increase efficiency it simply replace the defined code using "#define name val " and replace name with value 
//https://geeksforgeeks.org/macros-and-its-types-in-cpp


#include <iostream>

#define area(l, b) l*b
#define b 5

using namespace std;

int main() {
    int l = 7;
    
    int area = area(l, b); // with help of macros that area(l, b) looking like a function it will be replaced with "l*b" and as I defined b = 5 it actually replaced with "l*5"
    
    cout << area;

    return 0;
}





