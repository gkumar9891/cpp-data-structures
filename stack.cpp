#include <iostream>
#include <string>

using namespace std;

/** structure of stack using linked-list **/

class Node{

    public:
    string input;
    Node* next = NULL;

    Node(string data) {
        input = data;
    };
};

/** push in stack **/

void push(Node* &head, string data) {
        Node* n = new Node(data);
        Node* temp = head;

        if(temp == NULL) {
            head = n;
            return;     
        }

        head = n;
        n->next = temp; 
}

/** pop in stack **/

void pop(Node* &head) {
     head = head->next;
}

/** head pointer  **/

void peek(Node* head) {
    cout <<head->input <<"  ";
}

/** traversal of nodes **/

void traverse(Node* head) {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->input << " ";
            temp = temp->next;
        }
}

/** main function **/

int main() {

    Node* head = NULL;
    push(head, "hello");
    push(head, "how");
    push(head, "are");
    push(head, "you");
    // peek(head);
    pop(head);
    traverse(head);


    return 0;
}