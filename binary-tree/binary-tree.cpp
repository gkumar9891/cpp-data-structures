#include <iostream>
using namespace std;

class Node {
        public:
        int data;
        Node *left = NULL;
        Node *right = NULL;

        Node(int value) {
            data = value;
        } 
};

void preorder(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
}


int main() {

    Node* tree = new Node(1);
    tree->left = new Node(2);
    tree->right = new Node(3);
    tree->left->left = new Node(4);
    tree->left->right = new Node(5);
    tree->right->left = new Node(6);
    tree->right->right = new Node(7); 

   // preorder(tree);
   // inorder(tree);
    postorder(tree);
    return 0;
}