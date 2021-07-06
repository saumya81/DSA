    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        if(root==NULL)
            return ans;

        while(!q.empty()){
           TreeNode* t=q.front();
           q.pop();
               if(t!=NULL)
            {
                 v.push_back(t->val);
                 if(t->left)
                 q.push(t->left);
                 if(t->right)
                q.push(t->right);
  
            }
            else
            {
                 q.push(NULL); 
                   ans.push_back(v);
                    v.clear();
                //if two null comes consequtively then break
                if(q.front()==NULL)
                  break;
    
            }
        
        }
        return ans;
  
    }
