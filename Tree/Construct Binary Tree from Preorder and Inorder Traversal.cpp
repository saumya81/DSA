//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]



class Solution {
public:
int idx=0;
 TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int l,int h, unordered_map<int,int>& m){
    if(l>h)
    return NULL;
    int x=preorder[idx++];
    TreeNode* root=new TreeNode(x);
    if(l==h)
    return root;
    int mid=m[x];
    root->left=solve(preorder,inorder,l,mid-1,m);
    root->right=solve(preorder,inorder,mid+1,h,m);
    return root;

}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m ;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
       return solve(preorder,inorder,0,n-1,m);       

    }
};
