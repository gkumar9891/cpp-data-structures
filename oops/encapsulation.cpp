#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int rollNo;
        int age;

    public:
        int getRollNo() {
            return rollNo;
        }

        void setRollNo(int rollNo) {
            this->rollNo = rollNo;
        }
};

int main() {

    Student amar;
    amar.setRollNo(20);
    cout << amar.getRollNo();

    return 0;
}