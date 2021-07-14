//Maximum Sum BST in Binary Tree


class Solution {
public:
     class Info{
        public:
        int sum;
        int maxi;
        int mini;
        int ans;
        bool isBST;
    };
    Info solve(TreeNode* root) 
    {
       if(root == NULL){
            return {0, INT_MIN, INT_MAX, 0, true};
        }
        if(root->left == NULL and root->right == NULL){
            return {root->val, root->val, root->val, (root->val), true};
        }
        Info l=solve(root->left);
        Info r=solve(root->right);
        Info ret;
        ret.maxi = max(root->val, max(l.maxi, r.maxi));
        ret.mini = min(root->val, min(l.mini, r.mini));
        ret.sum = (root->val + l.sum + r.sum);
        if(l.maxi < root->val and root->val < r.mini and l.isBST and r.isBST){            
            return {ret.sum, ret.maxi, ret.mini, max(ret.sum, max(l.ans,r.ans)), true};
        }
        else{
            return {ret.sum, ret.maxi, ret.mini, max(l.ans,r.ans), false};
        }
        
    }
    int maxSumBST(TreeNode* root) {
        
        int  ans=solve(root).ans;
        return ans>0?ans:0;
       
        
       
        
        
        
    }
};
