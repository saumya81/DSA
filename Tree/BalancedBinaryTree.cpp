class Solution {
public:
   int height(TreeNode* root)
   {
       if(root==NULL)
           return 0;
       else
           return 1+max(height(root->right),height(root->left));
   }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
       else if (!(isBalanced(root->left) && isBalanced(root->right))) 
            return false;
        
        int l=height(root->left);
        int r=height(root->right);
        if(abs(l-r)<=1)
            return true;
        else
            return false;

    }
};
