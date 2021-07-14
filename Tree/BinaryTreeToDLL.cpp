class Solution
{
    public: 
     Node* prev=NULL;
    void convert (Node* p,Node* &head)
    {
        if(p==NULL)
        return ;
        convert(p->left,head);
        if(prev==NULL)// it will be NULL in case of first node
        head=p;
        else
        {
            p->left=prev; 
            prev->right=p;
        }
        prev=p;
        convert(p->right,head);
        
    }
    Node * bToDLL(Node *root)
    {
        Node* head=NULL;
        convert(root,head);
        return head;
        
    }
};
