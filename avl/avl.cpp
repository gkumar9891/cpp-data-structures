#include <iostream>
using namespace std;

class node {
    public:
    int key;
    node *left = NULL;
    node *right = NULL;
    int height = 1;

    node(int val) {
        key = val;
    }
};

int height(node *a) {
    if(a == NULL) {
        return 0;
    }

    return a->height;
}


int max(int a,int b) {
    return (a > b) ? a : b;
}

int getBalance(node *x, node* y) {
    return(height(x) - height(y));
}

node* leftRotate(node *x) {
    node* y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
    

}

node* rightRotation(node *x) {
    node* y = x->left;
    node* t2 = y->right;

    y->right = x;
    x->left = t2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

node *insert(node* root, int key) {
        if(root == NULL) {
            return(new node(key));
        }

        if(key < root->key) {
            root->left = insert(root->left, key);
        } else if(key > root->key) {
            root->right = insert(root->right, key);
        } else {
            return root;
        }

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root->left, root->right);
        
        if(balance > 1 && key < root->left->key) {
            return rightRotation(root);
        }

        if(balance > 1 && key > root->left->key) {
           root->left = leftRotate(root->left);
           return rightRotation(root);
        }



        return root;
}

void preorder(node* root) {

    if(root == NULL) {
        return;
    }

    cout << root->key << ' ';
    preorder(root->left);
    preorder(root->right);
}


int main() {

    node* root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 15);
    preorder(root);

    return 0;
}