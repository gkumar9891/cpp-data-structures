#include <iostream>
using namespace std;

class binaryNode {
    public:
    int data;
    binaryNode* left = NULL;
    binaryNode* right = NULL;

    binaryNode(int val) {
        data = val;
    }

};

class linkedNode {
    public:

    binaryNode* data;
    linkedNode* next = NULL;

    linkedNode(binaryNode* val) {
        data = val;
    }
};

class Queue {
    public:

    linkedNode* start = NULL;
    linkedNode* end = NULL;

    void push(binaryNode* val) {
        linkedNode* node = new linkedNode(val);
        if(start == NULL) {
            start = end = node;

            return;    
        }

        end->next = node;
        end = node;
    }

    binaryNode* front() {
        return start->data;
    }

    void pop() {
        linkedNode* temp = start;
        start = start->next;

        delete(temp);
    }

    bool empty() {
        if(start == NULL)
            return true;
        return false;
    }

};


void orderNTraversal(binaryNode* root) {
    if(root == NULL) {
        return;
    }

    Queue q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        binaryNode* node = q.front();
        q.pop();
        if(node != NULL) {
            cout << node->data << " ";
        
            if(node->left) {
                q.push(node->left);
            }

            if(node->right) {
                q.push(node->right);
            }
        }

        else if(!q.empty()) {
            q.push(NULL);
        }

    }

}


int main() {

    binaryNode* root = new binaryNode(1);
    root->left = new binaryNode(2);
    root->right = new binaryNode(3);
    root->left->left = new binaryNode(4);
    root->left->right = new binaryNode(5);
    root->right->left = new binaryNode(6);
    root->right->right = new binaryNode(7);

    orderNTraversal(root);


    return 0;
}