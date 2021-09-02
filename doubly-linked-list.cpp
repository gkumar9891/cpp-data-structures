#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;
    Node* prev = NULL;

    Node(int data2) {
        data = data2;
    }
};

void insertionAtEnd(Node* &head, int data) {
    Node* n = new Node(data);
    
    if(head == NULL) {
        head = n;
        return;
    } 

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
    temp->next->prev = temp; 
}

void insertionAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    if(head != NULL) {
         head->prev = n;
    }
    head = n;
}

void Display(Node* head) {
    while(head !=  NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

void deletionAtHead(Node* &head) {
     head = head->next;
     head->prev = NULL;
}

void deletionOfNode(Node* &head, int key){
    Node* temp = head;
    int count = 1;

    while(temp != NULL && temp->data != key) {
            temp = temp->next;
            count++;
    }

    if(count == 1) {
        deletionAtHead(head);
        return;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL) {
    temp->next->prev = temp->prev;
    }

    delete temp;
}

int main() {

    Node* head = NULL;

    insertionAtEnd(head, 5);
    insertionAtEnd(head, 2);
    insertionAtHead(head, 10);
    insertionAtHead(head, 100);
    deletionOfNode(head, 100);

    Display(head);

    return 0;
}