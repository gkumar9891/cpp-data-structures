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


node* successor(node* root) {
    node* current = root;
    while(current && current->left != NULL) {
        current = current->left;
    }

    return current;
}


node* deleteNode(node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    
    // if(root->data == key && root->left == NULL && root->right == NULL) {
    //     free(root);
    //     return NULL;
    // }
    
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    
    else {
        if(root->left == NULL ){
            node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        } else {
            node* temp = successor(root->right);
            root->data = temp->data;
            temp->data = key;
            root->right = deleteNode(root->right, key);
        }
    }

    return root;
}

void traversePreorder(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    traversePreorder(root->left);
    traversePreorder(root->right); 
}


int main() {

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);


    traversePreorder(root);
    deleteNode(root, 2);
    traversePreorder(root);


    return 0;
}