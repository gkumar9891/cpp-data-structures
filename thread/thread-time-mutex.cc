#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

int val = 0;
mutex m;
timed_mutex t;

void incrementor() {
 auto now = chrono::steady_clock::now();

 if(t.try_lock_until(now + chrono::seconds(2))) {
 val++;

 this_thread::sleep_for(chrono::seconds(1));
 t.unlock();
 }else {
  cout << "sorry cannot increment" << endl;
 }
}

int main() {
 thread t1(incrementor);
 thread t2(incrementor);

 t1.join();
 t2.join();

 cout << val << endl;
 return 0;
}
