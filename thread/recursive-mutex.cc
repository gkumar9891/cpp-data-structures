// recursive_mutex is used to lock many time unline simple try_lock/lock
// below recursive_mutes is used in recursion
// recursive_mutex is here to solve waiting problem if a critial region is already locked so the second thread have to wait for unlock to solve this recursive_mutex is used
// in recursive_mutex thread not wait for unlock actully it relock that critial region. 

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int counter = 0;
recursive_mutex m;

void incrementor(char c, int id) {
 if(id < 0) {
  return ;
 }
 m.lock();
 cout << "thread " << c << " and id  is "  << id << endl ;
 incrementor(c, --id);
 m.unlock();
}

int main() {

 thread t1(incrementor, '1', 10);
 thread t2(incrementor, '2', 10);

 t1.join();
 t2.join();

return 0;

}
