#include <iostream>

using namespace std;

class Student {
    string name;
    int age;
    int gradYear;
    int psp;

    Student(Builder builder) {
        if(builder.getGradYear() > 2023) {
            throw invalid_argument("graduation year show be less than 2023")
        }
    }
};
 