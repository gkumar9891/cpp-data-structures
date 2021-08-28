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

/** insertion at end **/

void insertAtEnd(Node* &head, int val) {
    Node* n = new Node(val);
    if(head == NULL) {

        head = n;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
}


/** insertion in the begining **/

void insertionInBegining(Node* &head, int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
}

/** insertion after a node **/ 

void insertionAfterNode(Node* &head, int val, int key){
    Node* temp = head;
    Node* n = new Node(val);

    while(temp->data != key) {
        temp = temp->next;
    }

    if(temp->next ==  NULL) {
        temp->next = n;
        return;
    }
    
    n->next = temp->next;
    temp->next = n;
}

/** searching for a key value **/

bool Search(Node* head, int key) {

        while(head != NULL) {
                if(head->data == key ) {
                    return true;
                } 

              head = head->next;  
        }

        return false;
}


/** display the values in list **/

void Display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->data << " ";
        temp=temp->next; 
    }
}

/** Deletion at the end **/

void deletionAtEnd(Node *head) {
    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}



/** Deletion at the begining **/ 

void deletionAtHead(Node* &head){
    head = head->next;
}

/* Deletion of Node **/ 

void deletionOfNode(Node* &head, int key) {
    Node* temp = head;
    if(temp->data == key) {
        deletionAtHead(head);
        return ;
    }
    while(temp->next->data != key) {
        temp = temp->next;
    }
    temp->next = temp->next->next;
}

/** reversal of linked-list **/

Node* reversalOfList(Node* &head) {
        
        Node* current = head;
        Node* previous  = NULL;
        Node* next;

        while(current != NULL) {
            next = current->next;
            current->next = previous;

            previous = current;
            current = next;
        }
        return previous;
}

Node* reversalOfListByReccursion(Node* head){
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rest = reversalOfListByReccursion(head->next);

    head->next->next = head;

    head->next = NULL;

    return rest;
}

/** append Last K nodes **/

Node* appendLastKNodes(Node* head, int k) {
    Node* temp = head;
    int length = 0;

    while(temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    Node* tail = temp;

    temp = head;

    for(int i = 0 ; i < length - k; i++) {
        temp = temp->next;   
    }

    Node* newHead = temp->next;

    Node* newTail = temp->next = NULL;

    tail->next = head;

    return newHead;
}


/** main function **/

int main() {

    Node* head = NULL;
    
    insertAtEnd(head, 5);
    insertAtEnd(head, 7);
    insertionInBegining(head, 2);
    insertAtEnd(head, 8);
    insertAtEnd(head, 12);
    insertionAfterNode(head, 100, 2);
    insertAtEnd(head, 9);
    insertAtEnd(head, 4);
    insertionAfterNode(head, 50, 9);
    // deletionOfNode(head, 8)  ;
    // Display(head);

    // head = reversalOfList(head);
    // head = reversalOfListByReccursion(head);
    // deletionAtEnd(head);
    // deletionAtHead(head);
    // deletionAtHead(head);

    // head = appendLastKNodes(head, 7);
    
    Display(head);

   // cout<< Search(head, 10);

    return 0;
}