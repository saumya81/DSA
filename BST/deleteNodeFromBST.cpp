Node* inSucc(Node* p , Node* &succParent)
    {
        p = p->right;
        while(p->left!=nullptr)
        {
            succParent = p;
            p = p->left;
        }
        return p;
    }
Node *deleteNode(Node *root,  int X)
{
    if(root==NULL)
    return root;
    if(root->data>X)
    root->left=deleteNode(root->left,X);
    else if(root->data<X)
    root->right=deleteNode(root->right,X);
    else
    {
        
        if(root->right==NULL)
        {
            Node* temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            Node* temp=root->right;
            delete(root);
            return temp;
        }
        else
        {
           Node* succParent = root;
                Node* succ = inSucc(root , succParent);
                
                swap(root->data ,succ->data);
            
                 root->right=deleteNode(root->right,X);
        }
    }
    return root;
}
