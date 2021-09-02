#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next = NULL;

    Node(int data2) {
        data = data2;
    }
};

void insertionAtHead(Node* &head, int data) {
    Node* n = new Node(data);
    if(head == NULL) {
        head = n;
        n->next = n;
        return;
    }

    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }

    n->next = head;
    head = n;
    temp->next = head;
}

void insertionAtTail(Node* head, int data) {
    Node* n = new Node(data);
    Node* temp = head;

     if(head == NULL) {
        head = n;
        n->next = n;
        return;
    }


    while(temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void deletionAtHead(Node* &head) {

        Node* temp = head;
        Node* todelete = head;

        while( temp->next != head) {
            temp= temp->next;
        }
        head = head->next;
        temp->next = head;


        delete(todelete);
}

void deletionAtTail(Node* &head) {
    Node* temp = head;
    while(temp->next->next != head) {
        temp = temp->next;
    }

    temp->next = head;




}

void Display(Node* head) {
    Node* temp = head;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);

}

int main() {

    Node* head = NULL;
    insertionAtHead(head, 1);
    insertionAtHead(head, 2);
    insertionAtHead(head, 5);
    insertionAtHead(head, 7);
    insertionAtTail(head, 3);
    deletionAtHead(head);
    deletionAtTail(head);
    Display(head);
    
    return 0;

}