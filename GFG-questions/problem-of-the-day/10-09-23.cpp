/*struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

Node* insertInBST(Node* root, int data) {
    if(root == NULL)
        return new Node(data);
    
    if(root->data > data)
        root->left = insertInBST(root->left, data);
    
    else if(root->data < data)
         root->right = insertInBST(root->right, data);

    return root;
}

class Solution
{
    public:
        Node* insert(Node* node, int data) {   
        return insertInBST(node, data);
    }
};