#include <iostream>
using namespace std;


class Stack{
    
   public:

    int* arr;
    int top = -1;

    Stack() {
        arr = new int[n];
    };

    void push(int data) {
        if(top == n - 1){
            cout << "stack overflow";
            return;
        }
        top++;
        arr[top] = data;
    }

    void pop() {
        if(top == -1) {
            cout << "there is no element in stack" << endl;
            return;
        }
        top--;
    }

    void Top() {
        if(top == -1){
            cout<<"no element in array";
            return;
        }
        cout<<arr[top];
    }

    bool empty() {
        return top == -1;       
    }
};

int main() {
    Stack disk;
    disk.push(5);
    disk.push(10);
    cout << disk.empty();
    disk.Top();
    return 0;
}