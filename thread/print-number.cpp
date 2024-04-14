#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    vector< thread* > tvector;

    for(int i = 0; i < 1000; i++) {
        thread *t1 = new thread([](int num) { cout << num << endl; }, i);
        tvector.push_back(t1);
    }

    //  thread *t1 = new thread([](int num) { cout << num << endl; }, 0);
    //  t1->join();

    // thread t1([](int num) { cout << num << endl; }, 0);
    // t1.join();


    for(auto t : tvector) {
        t->join();
    }



    return 0;
}