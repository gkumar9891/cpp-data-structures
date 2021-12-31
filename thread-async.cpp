//below is the exmaple of async in c++  below we can use async and deffered to make thread
//launch::deffered actully make a entry and in actual it not create any thread below it compute result on statement oddSum.get()
//launch::async actually create a thread at a time of execution of laynch::asynch 


#include <iostream>
#include <thread>
#include <mutex>
#include <future>

using namespace std;

typedef unsigned long int ull;

ull oddAdder(ull start, ull end) {

 ull sum = 0;
 
 for(int i = 0; i < end; i++) {
 if(i & 1) {
  sum += i;
 }

}

 return sum;
}

int main() {

 ull start = 0; ull end = 100000000;

 //future<ull> oddSum = async(launch::async, oddAdder, start, end);
 future <ull> oddSum = async(launch::deffered, oddAdder, start, end);

 cout << "waiting for the result" << endl;

 cout << "odd sum : " << oddSum.get() << endl;

 cout << "completed" << endl;

 return 0;
}
