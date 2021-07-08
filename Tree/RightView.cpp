// Given the root of a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.


vector<int> rightSideView(TreeNode* root) {
 
        vector<int> v;
          if(root==NULL)
            return v;
        queue<TreeNode*> q;
       vector<int> ans;
        q.push(root);
        q.push(NULL);
       
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                v.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                
            }
            else
            {
                q.push(NULL);
                ans.push_back(v.back());
                v.clear();
                if(q.front()==NULL)
                    break;
            }
        }
       
      
        return ans;
        
    }
