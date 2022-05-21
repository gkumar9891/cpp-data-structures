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

node* buildBST(node* root, int val) {
    
    if(root == NULL) {
        return new node(val);
    }
    
    if(val < root->data) {
        root->left = buildBST(root->left, val);
    } else {
        root->right = buildBST(root->right, val);
    }

    return root;
} 

void traverseInorder(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    traverseInorder(root->left);
    traverseInorder(root->right); 
}

int main() {

    int arr[] = {5, 1, 3, 4, 2, 7};
    node* root = NULL;
    root = new node(arr[0]);

    for(int i = 1; i < 6; i++)
        buildBST(root, arr[i]);  

    traverseInorder(root);

    return 0;
}