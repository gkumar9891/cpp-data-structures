#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next = NULL;

    Node(int val) {
        data = val;
    }
};

class Queue {
    public:
    Node* front = NULL;
    Node* back = NULL;

    void push(int val) {
        Node* n = new Node(val);

        if(front == NULL) {
            front = back = n;
            return;
        }

       back->next  = n;
       back = back->next;
    }

    void peek() {
        if(front == NULL) {
            cout << "nothing to display";
            return;
        }

        cout << front->data;
    }

    void pop() {
        Node* todelete = front;
        front = front->next;
        delete todelete;
    }

    bool empty() {
        if(front == NULL) {
            cout << true;
            return true;
        }

        cout << false;
        return false;

    }

};

int main() {

    Queue q;
    q.push(1);
    q.push(2);
    q.pop();
    q.peek();
    cout << endl;
    q.empty();


    return 0;
}