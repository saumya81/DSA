class BSTIterator {
public:
    vector<int>v;
    int i=0;
    void solve(TreeNode *root)
    {
     if(!root)
         return ;
     solve(root->left);
     v.push_back(root->val);
     solve(root->right);
    }
    BSTIterator(TreeNode* root) 
    {
       solve(root);    
    }
    
    int next() 
    {
        int ans=v[i];
        i++;
        return ans;
    }
    
    bool hasNext() {
        if(i!=v.size())
           return true;
        else return false;
        
    }
};
