class Solution {
public:
    bool solve(TreeNode* l,TreeNode* r)
    {
        if(!l && !r)
            return true;
        if(l&&r)
        {
            if(l->val ==r->val)
            {
                if(solve(l->left,r->right)&&solve(l->right,r->left)) return true;
            }
    
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
       return solve(root,root);
        
    }
};
