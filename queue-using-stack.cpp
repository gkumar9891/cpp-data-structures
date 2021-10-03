#include<iostream>
#include<stack>

using namespace std;

class Queue{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int val) {
        s1.push(val);
    }

    int pop() {
        if(s1.empty() && s2.empty()) {
            cout << "pop not possible";
            return -1;
        } 
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
        
    }

    void peek() {
         if(s1.empty() && s2.empty()) {
            cout << "pop not possible";
            return;
        } 
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
         cout << s2.top();
    }

    bool empty() {
        if(s1.empty() and s2.empty()) {
            cout << "empty";
            return true;
        }

        cout << "not empty";
        return false;
    }
};

int main() {

    Queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.pop();
    q.pop();
    q.pop();
    q.peek();
    q.empty();
    return 0;
}