
// Find the addition of all odd number from 1 to 1900000000 and also for the even number using thread

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

#define endVal 1900000000

using namespace std;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void sumOfOdd(ull start, ull end) {
	for(ull i = start; i <= end ;i++) {
		if((i % 2) != 0 ) {
			oddSum = oddSum + i;
		}
	}
	cout << "end of sumOfOdd" << endl;
}

void sumOfEven(ull start, ull end) {
	for(ull i = start; i <= end; i++) {
		if((i % 2) == 0) {
			evenSum = evenSum + i;
		}
	}
	cout << "end of sumOfEven" << endl;
}

void printer(ull start, ull end) {
	for(ull i = start; i < end; i++) {
	  cout << i << " ";
	}

}

int main() { 

 using namespace std::chrono;

 auto startTime = high_resolution_clock::now();

 //std::thread t1(sumOfOdd, 1, endVal);
 //std::thread t2(sumOfEven, 1, endVal);

  std::thread t1(printer, 1, 10);
  std::thread t2(printer, 20, 30);
  std::thread t3(printer, 40, 50);
 //sumOfOdd(1, endVal);
 //sumOfEven(1, endVal);

 t1.join();
 t2.join();
 t3.join();

 auto stopTime = high_resolution_clock::now();
 auto duration = duration_cast<microseconds>(stopTime - startTime);

 //cout << evenSum << endl;
 cout << oddSum << endl ;
 cout << duration.count() / 1000000 << endl;
 return 0;
}
