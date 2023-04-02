/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    if(head == NULL || head->next == NULL){
        return false;
    }
    
    while(fastPtr != NULL && fastPtr->next != NULL){
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr) {
        return true;
      }
    }
    return false;    
}