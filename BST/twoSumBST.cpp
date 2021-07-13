//iterative  with map
bool findTarget(TreeNode* root, int k) {
        
       unordered_map<int,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        m[k-root->val]=root;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
           
            if(m.find(temp->val)!=m.end() && m[temp->val]!=m[k-temp->val])
               return true;
            
             m[k-temp->val]=temp;
            if(temp->left)
               q.push(temp->left) ;
        
             if(temp->right)
               q.push(temp->right);
            
 
        }
        return false;
    }
};


//inorder+target sum
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v)
    {
        if(root==NULL)
            return;
       
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool findTarget(TreeNode* root, int k) {
        
     vector<int> v;
        inorder(root,v);
        int i=0,j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k)
                return true;
            else if(v[i]+v[j]>k)
                j--;
            else
                i++;
        }
        return false;
    }
};
