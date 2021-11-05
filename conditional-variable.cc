//condition variable is used to execute thread as per some condition like below is example for add and withdrow money

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

condition_variable cv;
mutex m;
int currentBalance = 0;

void addMoney(int amount) {
  lock_guard<mutex> lg(m);
  cout << "thread addMoney" << endl;
  currentBalance  = currentBalance + amount;
  cout << "Amount Added Current Balance is " << currentBalance << endl;
  cv.notify_one();
}

void withdrowMoney(int amount) {
 unique_lock<mutex> ul(m);
 cout << "thread withdrowMoney" << endl;
 cv.wait(ul, []{return (currentBalance != 0) ? true : false ; });

 if(currentBalance >= amount) {
  currentBalance = currentBalance - amount;
  cout << "Amount Deducted " << amount << endl;
 } else {
  cout << "Amount cannot be deducted because of insufficient balance" << endl;
 }

 cout << "current balance is " << currentBalance << endl;
}

int main() {
 
 thread t1(addMoney, 500);
 thread t2(withdrowMoney, 600);

 t1.join();
 t2.join();

 return 0;

}


