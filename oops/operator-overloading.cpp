#include <iostream>
using namespace std;

class Complex {
    public:
    
    int real;
    int imag;

    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    void display() {
        cout << real << " + i" << imag;
    }

    Complex operator + (Complex &c) {
       Complex c2;
       c2.real = real + c.real;
       c2.imag = imag + c.imag;

       return c2;
    }   
};


int main() {

    Complex c1(5, 6), c2(7, 8);
    Complex c3;
    c3 = c1 + c2;
    c3.display();

    return 0;
}