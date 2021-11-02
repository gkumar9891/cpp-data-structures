// In thread join used to join the thread  with main thread or process ( int main() )
// with join we wait for the thread finish so it always if we crate a thread and the join the it is fact that we will get output as pert instruction in thread
// with detach we don't wait for the thread completion  it is like to asynch function and it is not always possible to get output as per the thread because it can be possible the main process finish first compare than it child thread.




#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


void timer(int time) {
	while( time --> 0) {
		cout << "Hii I am gaurav" << endl;
	}

	this_thread::sleep_for(chrono::seconds(3));
}

int main() {
	
	thread t1(timer, 10);
	// t1.join();
	t1.detach();
	if( t1.joinable() )
		t1.join();

	cout << "miss me" << endl;

	return 0;
}
