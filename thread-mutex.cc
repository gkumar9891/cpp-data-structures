//mutex is used to avoid race condition
// lets seee race condition with example in below if two thread is accessing same variable at a time so we the variable a will become 1 but it actually become 2
// to avoid the race condition mutex is used for.
#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int a = 0;
std::mutex m;

void incrementor() {
// example of mutex lock function and usage

//	m.lock();
//	a++;
//	m.unlock();

for(int i = 0; i < 100000; i++) {
   if( m.try_lock() ){
	a++;
      m.unlock();
   }
  }
}

int main() {

 
 thread t1(incrementor);
 thread t2(incrementor);

 t1.join();
 t2.join();

 cout << a << endl;



 return 0;

}
