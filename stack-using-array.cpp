#include <iostream>
using namespace std;
#define n 5

/** struction of stack using array **/

class Stack {
    
   public:

    int* arr;
    int top = -1;

    Stack() {
        arr = new int[n];
    };

    /** push in stack **/

    void push(int data) {
        if(top == n - 1){
            cout << "stack overflow";
            return;
        }
        top++;
        arr[top] = data;
    }

    /** pop in stack **/

    void pop() {
        if(top == -1) {
            cout << "there is no element in stack" << endl;
            return;
        }
        top--;
    }

    /** display the top / head node **/

    void Top() {
        if(top == -1){
            cout<<"no element in array";
            return;
        }
        cout<<arr[top];
    }

    /** check stack for empty **/
    bool empty() {
        return top == -1;       
    }
};

/** main function **/

int main() {
    Stack disk;
    disk.push(5);
    disk.push(10);
    disk.push(20);
    disk.push(30);
    cout << disk.empty();
    disk.Top();
    return 0;
}