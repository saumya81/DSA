//Build tree from inorder and preorder

class Solution {
public:
      int idx=0; 
    TreeNode* solve(vector<int>& pre, vector<int>& in,int l,int h,unordered_map<int,int> &m){
        if(l>h)
            return NULL;
        int x=pre[idx++];
        TreeNode* root=new TreeNode(x);
       if(l==h)
           return root;
        int mid=m[x];
        root->left=solve(pre,in,l,mid-1,m);
        root->right=solve(pre,in,mid+1,h,m);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int n)
    {
         unordered_map<int,int> m;
 
      
       for(int i=0;i<n;i++)
           m[inorder[i]]=i;
        
        return solve(preorder,inorder,0,n-1,m);
    }
        
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
       return build(preorder,inorder,preorder.size());
        
    }
};
