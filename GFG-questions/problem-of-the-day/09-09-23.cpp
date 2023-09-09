struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
void preOrder(Node *root, vector<int> &orderArray) {
    if(root) {
        preOrder(root->left, orderArray);
        orderArray.push_back(root->data);
        preOrder(root->right, orderArray);
    }
}

class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        vector<int> orderArray;
        
        preOrder(root, orderArray);
        reverse(orderArray.begin(), orderArray.end());
        
        return orderArray[K-1];
        
        //Your code here
    }
};