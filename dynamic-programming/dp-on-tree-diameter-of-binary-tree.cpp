// https://leetcode.com/problems/diameter-of-binary-tree/

#include <bits/stdc++.h>
using namespace std;
int solve(TreeNode *root, int& res) {
    if(root == NULL)
        return 0;
    
    int l = solve(root->left, res);
    int r = solve(root->right, res);

    int temp = max(l, r) + 1;
    int ans = max(temp, 1 + l + r);
    res = max(res, ans);

    return temp;
}

int main() {
    int ans = INT_MIN;
    solve(root, ans);
    return ans - 1; 
}