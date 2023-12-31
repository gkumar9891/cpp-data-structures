#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

typedef long int ull;

promise <ull> oddSum;
future <ull> oddFuture = oddSum.get_future();


void sumOfOdd( promise<ull>&& oddSum, ull start, ull end) {
 ull sum = 0;
 for(ull i = start; i < end; i++) {
	if(i & 1) {
	sum += i;
   }
 }

 oddSum.set_value(sum);
};


int main() {

  
 ull start = 0; 
 ull end = 1000000000;


 cout << "Thread created" << endl;

 thread t1(sumOfOdd, move(oddSum), start, end);
 
 cout << "waiting for the result" << endl;
 cout << "sum of odd number is " << oddFuture.get() << endl;

 t1.join();

 return 0;

}
