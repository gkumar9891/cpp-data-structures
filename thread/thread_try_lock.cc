//To pass a variable with reference you need to use some reference-wrapper like ref in just only thread
// try_lock is used for pass many sharable resource 

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

int x = 0;
int y = 0;

mutex m1,m2;

void sleeper(int sec){
 this_thread::sleep_for(chrono::seconds(sec));
}

void incrementor(int& val, mutex& m, const char* variable ){
	for(int i = 0; i < 5; ++i){
      		m.lock();
		 ++val;
		cout << variable << val << endl; 
      		m.unlock();
       		sleeper(1); 
       }
}

void adder(){
	int useCount = 5;
	int sum = 0;

	while(1) {
		int locker = try_lock(m1, m2);
		if(locker == -1) {
		if(x != 0 && y != 0) {
			--useCount;
			sum += x + y;
			cout << "x+y = " << sum << endl;
			x = 0;
			y = 0;
			cout << "-----------------" << endl;
		}
		m1.unlock();
		m2.unlock();
		}

		if(useCount == 0) break;
	}

}

int main() {

	thread t1(incrementor, ref(x), ref(m1), "x ");
	thread t2(incrementor, ref(y), ref(m2), "y ");
	thread t3(adder);

	t1.join();
	t2.join();
	t3.join();
	return 0;
}
