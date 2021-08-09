class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            Node* temp=q.front();
            q.pop();
  
             if(temp!=NULL)
            {
                Node* n=q.front(); 
                temp->next=n;
                if(temp->left)
                q.push(temp->left);   
                
                if(temp->right)
                q.push(temp->right);
  
            }
            else
            {
                q.push(NULL);
                if(q.front()==NULL)
                    break;
            }
          
        }
        return root;
    }
};
