#include <iostream>
using namespace std;

class Queue {
    public:
    int data;
    Queue* next = NULL;

    Queue(int input) {  
        data = input;
    } 
};

void enqueue(Queue* &front, Queue* &back, int data) {
    Queue* n = new Queue(data);

    if(front == NULL) {
        front = back = n;
        return;
    }
    back->next = n;
    back = n->next;
}

void dequeue(Queue* &front) {
    front = front->next;
}

void peek(Queue* front) {
    cout << front->data;
}

bool empty(Queue* front) {
    if(front == NULL) {
        cout << true;
        return true;
    }
      cout << false;
     return false;
}


int main() {

    Queue* front = NULL;
    Queue* back = NULL;

    enqueue(front, back, 1);
    enqueue(front, back, 2);
    dequeue(front);
    empty(front);
    cout << endl;
    peek(front);
    

    return 0;

}