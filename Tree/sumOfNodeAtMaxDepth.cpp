//here the intution is .. we go level by level and check if it is max level we'll add it to sum else if the level is greater than max level then
//sum will be starting from that level and maxlevel will be that level


class Solution {
public:
  int sum=0;
    int max=INT_MIN;
    void solve(TreeNode* root,int level)
    {
             if(root==NULL)
            return;
            if(level>max)
            {
                max=level;    
                sum=root->val;
            }
            else if(level==max)
            {
                sum=sum+root->val;
            }  
            solve(root->left,level+1);
            solve(root->right,level+1);

            
}
    int deepestLeavesSum(TreeNode* root) {
       int level=0;
        int max=0;
        solve(root,level);
        return sum;
    }
};
