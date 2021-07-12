class Solution {
public:
    bool validate(TreeNode* root,long long l,long long h)
    {
        if(root==NULL)
            return true;
        if(root->val<=l || root->val>=h)
            return false;
       return  validate(root->left,l,root->val)&&validate(root->right,root->val,h);
    }
    bool isValidBST(TreeNode* root) {
        
      return  validate(root,-100000000000,100000000000);
        
    }
};
