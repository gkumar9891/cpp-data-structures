
class Solution{
public:
    unordered_set<int> postorder(Node* root,int &ans,int k){
        if(root==NULL){
            unordered_set<int> container;
            return container;
        }
        unordered_set<int> leftSubTree = postorder(root->left,ans,k);
        unordered_set<int> rightSubTree = postorder(root->right,ans,k);
        unordered_set<int> subTree;
        
	for(auto el : leftSubTree){
            subTree.insert(el);
        }

        for(auto el : rightSubTree){
            subTree.insert(el);
        }

        subTree.insert(root->data);
        if(subTree.size()<=k){
            ans++;
        }
        return subTree;
    }
    
    int goodSubtrees(Node* root,int k){
        // Code here
        int ans=0;
        postorder(root,ans,k);
        return ans;
    }
};