class Solution {
public:
  
     TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int l,int h, unordered_map<int,int>& m,int& idx)
     {
         if(l>h)
             return NULL;
         int x=postorder[idx--];
         TreeNode* root=new TreeNode(x);
         if(l==h)
             return root;
         int mid=m[x];
        
          root->right= solve(inorder,postorder,mid+1,h,m,idx);
          root->left= solve(inorder,postorder,l,mid-1,m,idx);
         return root;
     }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      unordered_map<int,int> m;
         
        int n=inorder.size();
         int idx=n-1;
        for(int i=0;i<n;i++)
          m[inorder[i]]=i;
        return solve(inorder,postorder,0,n-1,m,idx);
        
    }
};
