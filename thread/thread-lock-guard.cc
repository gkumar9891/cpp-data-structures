// lock guard is used to omit  m.unlock()

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
mutex m1;

void incrementor(const char* threadName, int val) {
 //  m1.lock below is replacement code for lock guard

 lock_guard<mutex> lock(m1);
 for(int i = val; i > 0; i--){
  cout << threadName << " is executing " << i << endl;
 }

}

int main() {

 thread t1(incrementor, "t1", 10);
 thread t2(incrementor, "t2", 10);

 t1.join();
 t2.join();

 cout << counter << endl;
 return 0;
}
