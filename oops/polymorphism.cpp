// basic defintion is poly means many morph forms
// for exmaple  a man can be a fater, brother, uncle, son  
// polymorphism are two types
// 1. compile time
//     1. function overloading
//     2. operator overloading

// 2. run time
//     1. function overriding

#include <iostream>
using namespace std;


// example of function overloading 
class Parent {
public:
    int a;
    int b;


    void printA_B(string c) {
        cout << a << " "<< b;
    }

    virtual void printA_B(char c) {
        cout << "char function called from parent" << endl;
        cout << a << " "<< b;
    }


    // example of operator overloading
    int operator+ (Parent p) {
        return a - p.a;
    }
    // end of overator overloading example
};
// end of function overloading example


class Child : public Parent {
    public:
    void printA_B(char c) {
        cout << "char function called from child" << endl;
        cout << a << " "<< b;
    }
};

int main() {

    Parent obj1;
    Child obj2;
    Parent *p;
    p = &obj2;

    p->printA_B('a');
    
    // obj2.printA_B('c');
    // obj1.a = 10;
    // obj2.a = 5;
    // cout << endl << obj1 + obj2;

    return 0;
}