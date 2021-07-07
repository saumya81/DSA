/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solveMPS(TreeNode* root,int &res)
    {
        if(root==NULL)
            return 0;
        int l=solveMPS(root->left,res);
        int r=solveMPS(root->right,res);
        int temp=max(max(l,r)+root->val,root->val);
        int ans=max(temp,l+r+root->val);
         res=max(res,ans);
        return temp;
    }
public:
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int ans=solveMPS(root,res);
        return max(ans,res);
    }
};
