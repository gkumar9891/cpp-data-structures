class Solution{
    public:

    struct Node* reverse(struct Node* head, struct Node* altNode) {
        struct Node *next = NULL;
        struct Node *prev = altNode;
        struct Node *current = head;
        
        while(current != altNode) {
            next = current->next;
            current->next = prev;
            
            prev = current;
            current = next;
        }
        
        return prev;
    }
    
    struct Node* modifyTheList(struct Node *head)
    {
        head = reverse(head, NULL);
        
        struct Node *slow = head;
        struct Node *fast = head;
        
        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if(fast->next != NULL) {
            slow = slow->next;
        }
        
        head = reverse(head, slow);
        
        struct Node* temp = slow;
        struct Node* start = head;
        
        if(fast->next == NULL) {
            slow = slow->next;
        }
        
        while(slow != NULL) {
            head->data = head->data - slow->data;
            head = head->next;
            slow = slow->next;
        }
        
        start = reverse(start, temp);
        
        return start;
    }
};