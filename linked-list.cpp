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

/** make circle loop of node **/

void makeCircle(Node* head, int pos) {
    Node* temp = head;
    Node* startNode;
    int count = 1;
    
    while(temp->next != NULL) {
        if(count == pos) {
            startNode = temp;
        }
        
        temp = temp->next;
        count++;
    }

    temp->next = startNode;
}

int findLength(Node* head) {
    int count = 1;
    if(head->next == NULL) {
       return count;
    }

    while(head->next != NULL) {
        count++;
        head = head->next;
    }

    return count;
}


/** check for the node is circle present or not **/

int checkForCircle(Node* head) {
    Node* fastMover = head;
    Node* slowMover = head;

    while(fastMover != NULL && fastMover->next != NULL) {
        slowMover = slowMover->next;
        fastMover = fastMover->next->next;

        if(fastMover == slowMover) {
            return 0;
        }
    }

    return 1;
}

/** deletion of circle or node **/

void deletionOfCircle(Node* head) {
    Node* fastMover = head;
    Node* slowMover = head;

    do {
         slowMover = slowMover->next;
        fastMover = fastMover->next->next;
    } while(fastMover != slowMover); 

    fastMover = head;
    while(slowMover->next != fastMover->next) {
        slowMover = slowMover->next;
        fastMover = fastMover->next;
    }

    slowMover->next = NULL;

}

/** linked-list intersetction **/
void makeInterSection(Node* head, Node* head2, int pos) {
       int lengthOfHead = findLength(head);
       int lengthOfHead2 = findLength(head2); 
      

      if(lengthOfHead > lengthOfHead2 && lengthOfHead > pos) {
           

            while(head2->next != NULL) {
                head2 = head2->next;
                
            }

            int count = 1;
            while(count != pos) {
                head = head->next;
                count++;
            }

            head2->next = head;
       }      
}


/** detection of intersection **/

int detectionOfIntersection(Node* head, Node* head2 ) {
        int lengthOfHead = findLength(head);
        int lengthOfHead2 = findLength(head2);

        Node* ptr1;
        Node* ptr2;
        int difference;

        if(lengthOfHead > lengthOfHead2) {
            ptr1 = head;
            ptr2 = head2;
            difference = lengthOfHead - lengthOfHead2;
        } else {
            ptr1 = head2;
            ptr2 = head;
            difference = lengthOfHead2 - lengthOfHead;
        }
        
        while(difference != 0) {
                ptr1 = ptr1->next;
                difference--;
        }

        while(ptr1 != ptr2) {
                if(ptr1->next ==  NULL) {
                return -1;
                }
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
        }

        return (ptr1->next->data);
 }

//funciton for adding sorted list from two sorted linkded list 

Node* mergeTwoList(Node* &head, Node* &head2) {
    Node* ptr1 = head;
    Node* ptr2 = head2;
    Node* dummyNode = new Node(-1);
    Node* ptr3 = dummyNode;

    while(ptr1 != NULL && ptr2 !=  NULL) {
        if(ptr1->data > ptr2->data) {
            ptr3->next = ptr2;
            ptr2 = ptr2->next; 
        } else {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        ptr3 = ptr3->next;
    }

    while(ptr1 != NULL) {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while(ptr2 != NULL) {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    
    return dummyNode->next;

}


// function for adding odd position first and than even like 1 2 3 4 5 6 -> 1 3 5 2 4 6

void oddEvenPosition(Node* &head) {

    Node* odd = head;
    Node* even = odd->next;
    Node* evenPoint = odd->next;

    while(odd->next != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;

        if(odd->next != NULL){
        even->next = odd->next;
        even = even->next;
        } else {
            even->next = NULL;
        }
    }

    odd->next = evenPoint;

}



/** main function **/

int main() {

    Node* head = NULL;
    Node* head2 = NULL;
    
    // insertAtEnd(head, 5);
    // insertAtEnd(head, 7);
    // insertionInBegining(head, 2);
    // insertAtEnd(head, 8);
    // insertAtEnd(head, 12);
    // insertionAfterNode(head, 100, 2);
    // insertAtEnd(head, 9);
    // insertAtEnd(head, 4);
    // insertionAfterNode(head, 50, 9);
    // deletionOfNode(head, 8)  ;
    // Display(head);

    // head = reversalOfList(head);
    // head = reversalOfListByReccursion(head);
    // deletionAtEnd(head);
    // deletionAtHead(head);
    // deletionAtHead(head);

    // head = appendLastKNodes(head, 7);
    // makeCircle(head, 4);
    // // cout << checkForCircle(head);
    
    // deletionOfCircle(head);

    //  insertAtEnd(head2, 90);
    //  insertAtEnd(head2, 100);
    //  insertAtEnd(head2, 80);

    //  Display(head2);

    //  makeInterSection(head, head2, 4);

    //  Display(head);
    //  cout << endl;
    //  Display(head2);

    // int intersectionResult = detectionOfIntersection(head, head2);
    // cout << intersectionResult;
  // cout<< Search(head, 10);

  insertAtEnd(head, 5);  //1
  insertAtEnd(head, 14); //2
  insertAtEnd(head, 15); //3
  insertAtEnd(head, 16); //4
  insertAtEnd(head, 17); //5
  insertAtEnd(head, 18); //6
  insertAtEnd(head, 19); //7


  oddEvenPosition(head);
  Display(head);



//   insertAtEnd(head2, 4);
//   insertAtEnd(head2, 7);
//   insertAtEnd(head2, 10);



//   Display(head);
//   cout<<endl;
//   Display(head2);
  
//   Node* head3 = mergeTwoList(head, head2);
//   cout<<endl;
//   Display(head3);

    return 0;
}