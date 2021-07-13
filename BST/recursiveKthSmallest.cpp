//inorder traversal for checking

class Solution {
public:
    int res;
    void solve(TreeNode* root, int &k) {
       if (!root) return;
        solve(root->left, k);
        if (--k == 0)
            res = root->val;
        solve(root->right, k);
       
    }
    int kthSmallest(TreeNode* root, int k) {
       solve(root,k);
        return res;
    }
};
