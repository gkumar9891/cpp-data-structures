#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next = NULL;

    Node(int val) {
        data = val;
    };
};

class Dequeue {
    public:

    Node *front = NULL;
    Node *rear = NULL;

    void insertFromFront( int value ) {
        Node *n = new Node(value);

        if(front == NULL) {
            front = rear = n;
            return ;
        }

        n->next = front;
        front = n;

    }


    void traverseFromFront() {
        if(front == NULL) {
            return;
        }

        while(front != NULL) {
          cout << front->data;
          front = front->next;
        }
    }

};


int main() {

    Dequeue d;
    d.insertFromFront(3);
    d.insertFromFront(7);
    d.insertFromFront(12);
    d.traverseFromFront();

    return 0;
}