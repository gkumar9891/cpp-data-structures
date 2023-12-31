#include <iostream>
#include <mutex>
#include <thread>
#include <stack>
#include <condition_variable>

using namespace std;

stack <int> buffer;
mutex m;

int val = 100;

condition_variable cv;

void producer() {
 while(val != 0){
  unique_lock <mutex> lock(m);
  cv.wait(lock, []{ return buffer.size() < 50; });
  buffer.push(val);
  cout << "produced " << val << endl;
  val--;
  m.unlock();
  cv.notify_one();
 }
}

void consumer() {
 while(true){
  unique_lock <mutex> lock(m);
  cv.wait(lock, []{ return buffer.size() > 0; });

  cout << "consumed " << buffer.top() << endl;
  buffer.pop();
  m.unlock();
  cv.notify_one();
  if(val == 0 && buffer.size() == 0) {
  break;
  }
}
}

int main() {

 thread t1(producer);
 thread t2(consumer);

 t1.join();
 t2.join(); 

 return 0;
}
