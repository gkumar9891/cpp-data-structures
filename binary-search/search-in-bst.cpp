#include <iostream>
using namespace std;

class node {
    public:

    int data;
    node* left = NULL;
    node* right = NULL;

    node(int val) {
        data = val;
    }
};


node* searchInBST(node* root, int key) {
    
    if(root == NULL) {
        return NULL;
    }

    if(root->data == key) {
        return root;
    }

    if(key < root->data) {
        return searchInBST(root->left, key);
    }

    return searchInBST(root->right, key);
}


int main() {


    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);

    if(searchInBST(root, 12) == NULL) {
        cout << "key not found";
    } else {
        cout << "key found";
    }




    return 0;
}