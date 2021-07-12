class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
       if(root==NULL)
           return NULL;
        while(root){
            if(val==root->val)
                return root;
             if(val<root->val)
             {
                 if(root->left)
                 root=root->left;
                 else break; //no element present in left which is less than the val
             }
            if(val>root->val)
             {
                 if(root->right)
                 root=root->right;
                 else break; //no element present in right which is greater than the val
             }
            
        }
        return NULL;
        
    }
};
