#include <iostream>
#define queueSize 2

using namespace std;

class queue {
    public:

    // structure of queue
    int *arr = new int[queueSize];
    int front = -1;
    int back = -1;


    //insertion in queue
    void enqueue(int data) {
        if(front == -1) {
            front++;
        }

        if(back == queueSize - 1) {
            cout << "insertion in queue not possible";
            return;
        }

        back++;
        // *(arr + back) = data;   // array in pointer
        arr[back] = data;
    }

    //current element in queue
    void peek() {
        cout << *(arr + front);
    }

    //deletion in queue
    void dequeue() {
        if(front == -1) {
            cout << "dequeue is not possible";
            return;
        }
        front++;
    }

    //check for the container
    bool empty() {
        if(front > back || front == -1) {
            return true;
        }
        return false; 
    }
};

int main() {

    queue list;
    list.enqueue(1);
    list.dequeue();
    list.enqueue(2);
    
    // list.dequeue();

    list.peek();
    // cout << list.empty();
    return 0;
}