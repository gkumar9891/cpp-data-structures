#include <iostream>
using namespace std;

class Human {
    public:
        string name;
        int age;
        int weight;

        int getAge() {
            return age;
        }

        void setName(string name) {
            this->name = name;
        }    
};

class Child : private Human {
    public:
        string color;
        string getColor() {
            return color;
        }
};

int main() {

    Child amar;
    amar.color = "brown";
    // amar.name = "amar";
    // amar.setName("amar");
    // cout << amar.name << endl;
    cout << amar.getColor();

    return 0;
}
