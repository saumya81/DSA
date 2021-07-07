// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.


class Solution {
public:
    int maxPath(TreeNode* root,int &res)
    {
         if(root==NULL)
            return 0;
        int l=maxPath(root->left,res);
        int r=maxPath(root->right,res);
        int temp=max(l,r);
        int ans=max(temp,(l+r));
        res=max(res,ans);
        return temp+1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
       
        if(root==NULL)
            return 0;
        int res=0;
       maxPath(root,res);
        return res;
        
        
    }
};
