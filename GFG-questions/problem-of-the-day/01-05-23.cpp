//User function Template for C++

unordered_map <string, int> container;

class Solution{
public:
    string help(Node *root) {
        string temp = to_string(root->data);
        
        for(auto el : root->children) {
            string t = help(el);
            temp = temp + t + "*";
        }
        
        container[temp]++;
        return temp;
    }

    int duplicateSubtreeNaryTree(Node *root){
        // Code here
        
        container.clear();
        
        help(root);
        int ans = 0;
        
        for(auto el : container) {
            if(el.second > 1) ans++;
        }
        
        return ans;
    }
};