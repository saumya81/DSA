https://leetcode.com/explore/challenge/card/august-leetcoding-challenge-2021/615/week-3-august-15th-august-21st/3903/
https://www.youtube.com/watch?v=8WL9lUp8EvE


Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
--------------------------------------------------------------------------------------
#define ll long long
class Solution {
public:
     ll totalSum=0;
    ll total(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return root->val+total(root->left)+total(root->right);
    }
    ll solve(TreeNode* root,ll &maxi)
    {
        
        if(root==NULL)
            return 0;
        ll l=solve(root->left,maxi);
        ll r=solve(root->right,maxi);
        ll up=totalSum-l-r-root->val;
        ll op1=up*((ll)root->val+l+r);
        ll op2=l*((ll)root->val+up+r);
         ll op3=r*((ll)root->val+up+l);
        maxi=max(maxi,max(max(op1,op2),op3));
        return l+r+root->val;
        
    }
    int maxProduct(TreeNode* root) {
       totalSum=total(root); 
        ll maxi=-1;
        solve(root,maxi);
        return maxi%1000000007;
        
    }
};
