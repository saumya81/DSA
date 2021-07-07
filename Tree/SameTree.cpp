//Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.   


bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL)
            return true;
     if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
         if(p->val!=q->val)
            return false;
       return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
     
    }