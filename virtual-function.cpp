#include <iostream>
using namespace std;

class Base{
    public:
    virtual void print() {
        cout << "this is print of Base class" << endl;
    }

    virtual void display() {
        cout << "this is display of Base class" << endl;
    }
};

class Child : public Base {
    public: 
    void print() {
        cout << "this is print of Child class" << endl;
    }

    void display() {
        cout << "this is display of Child class" << endl;
    }
};


int main() {

    Base *p, o1;
    Child o2;
    p = &o2;
    p -> print();

    return 0;
}