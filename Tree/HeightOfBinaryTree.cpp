   
//A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

int maxDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        int l=maxDepth(root->left)+1;
         int r=maxDepth(root->right)+1;
        return max(l,r);
   
    }
