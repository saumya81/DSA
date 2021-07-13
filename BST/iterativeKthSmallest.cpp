class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode*> s;
        while(root || !s.empty()){
           
            while(root)
               {  s.push(root);
               root=root->left;}
            root=s.top();
            s.pop();
            if(--k==0)
                return root->val;
            root=root->right;
        }
        return -1;
    }
};
