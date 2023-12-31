#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

class printHello {
    public:

    void run() {
        int sum = 0;
        for(int i = 0; i < INT_MAX; i++) {
            sum += i;
        }

        cout << sum;
    }
};

int main() {
    auto startTime = high_resolution_clock::now();

    // printHello *obj = new printHello();
    // obj->run();
    // obj->run();
    // obj->run();
    // obj->run();


    thread t1( [](printHello *obj) {
        obj->run();
    }, new printHello());

    thread t2( [](printHello *obj) {
        obj->run();
    }, new printHello());

       thread t3( [](printHello *obj) {
        obj->run();
    }, new printHello());

    thread t4( [](printHello *obj) {
        obj->run();
    }, new printHello());

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << endl << duration.count() / 1000000 << endl;
    return 0;
}