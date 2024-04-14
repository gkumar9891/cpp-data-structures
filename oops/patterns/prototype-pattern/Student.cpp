#include <bits/stdc++.h>
using namespace std;

class Student;

//interface
template<typename T> class Prototype {
    virtual T* clone() = 0;
};

//Registry class 
class StudentRegistry {
    public:
    unordered_map<string, Student*> mp;

    void registerStudent(string key, Student *student) {
        mp[key] = student;
    }

    Student *getStudent(string key) {
        return this->mp[key];
    }

};


//student class
class Student : Prototype<Student> {
    private:
    string name;
    int age;
    double psp;
    string batchname;
    double avgBatchPsp;

    public:
    // string getName() {
    //     return this->name;
    // }

    Student() {};

    //constuctor will create its own object and will return with this values
    Student(Student *student) {
        this->avgBatchPsp = student->avgBatchPsp;
        this->batchname = student->batchname;
    }

    void setName(string name) {
        this->name = name;
    }

    // int getAge() {
    //     return this->age;
    // }

    void setAge(int age) {
        this->age = age;
    }

    void setpsp(double psp) {
           this->psp = psp; 
    }

    void setBatchname(string batchname) {
       this->batchname = batchname; 
    }

    void setAvgBatchPsp(double avgBatchPsp) {
       this->avgBatchPsp = avgBatchPsp;
    }

    // double getpsp() {
    //     return this->psp;
    // }

    // string getBatchname() {
    //    return this->batchname;
    // }

    // double getAvgBatchPsp() {
    //    return this->avgBatchPsp;
    // }

    Student *clone() {
        // Student *stCopy = new Student;
        // stCopy->avgBatchPsp = this->avgBatchPsp;
        // stCopy->batchname = this->batchname;

        return new Student(this);
    }

};

class IntelligentStudent : public Student {
    public:
    IntelligentStudent() {}
    
    //copy constructor which first call it super constructor
    IntelligentStudent(IntelligentStudent *student) : Student(student) {}

    IntelligentStudent *clone() {
        // IntelligentStudent *student = new IntelligentStudent();
        // student->setAvgBatchPsp(this->getAvgBatchPsp());
        // student->setBatchname(this->getBatchname());
        return new IntelligentStudent(this);
    }
};

void fillRegistry(StudentRegistry *studentRegistry) {
    Student *student2022Prototype = new Student();
    student2022Prototype->setBatchname("sept22");
    student2022Prototype->setAvgBatchPsp(85.0);


    Student *intelligentStudnet2022Prototype = new IntelligentStudent();
    intelligentStudnet2022Prototype->setBatchname("sept22Intelligent");
    intelligentStudnet2022Prototype->setAvgBatchPsp(99);

    studentRegistry->registerStudent("sept22", student2022Prototype);
    studentRegistry->registerStudent("sept22Intelligent", intelligentStudnet2022Prototype);
}

int main() {

    StudentRegistry *studentRegistry = new StudentRegistry();
    fillRegistry(studentRegistry);

    Student *gaurav = studentRegistry->getStudent("sept22")->clone();
    gaurav->setName("gaurav");
    gaurav->setAge(23);
    gaurav->setpsp(50);

    Student *ravi = studentRegistry->getStudent("sept22Intelligent")->clone();
    ravi->setName("ravi");
    ravi->setAge(25);
    ravi->setpsp(90);

    return 0;
}