class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<Node*> v;
     //   vector<vector<Node*>> ans;
      //  root->next=NULL;
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
            if(temp!=NULL)
            {
                
                if(temp->left)
                {
                   v.push_back(temp->left); 
                    
                    q.push(temp->left);
                }
                if(temp->right)
                {
                     v.push_back(temp->right); 
                    q.push(temp->right);
                    
                }
            }
            else
            {
                q.push(NULL);
                for(int i=0;i<v.size();i++)
                {
                   if(i<v.size()-1)
                   v[i]->next=v[i+1];
                    else
                        v[i]->next=NULL; 
                   
                }
                
                if(q.front()==NULL)
                    break;
                 v.clear();
            }
        }
        return root;
    }
};
