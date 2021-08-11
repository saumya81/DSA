struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* head)
    {
        Node* cur=head;
        Node* prev=NULL;
        while(cur)
        {
            Node* temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* l1=reverse(first);
        Node* l2=reverse(second);
         int carry=0;
        Node* s=new Node(0);
        Node* head=s;
        while(l1 || l2 || carry)
        {
          int sum=0;
          if(l1)
              { 
                  sum=sum+l1->data;
                  l1=l1->next;
              }
          if(l2)
              {
                sum=sum+l2->data;
                  l2=l2->next;
              }
            sum=sum+carry;
            carry=sum/10;
            Node* temp=new Node(sum%10);
            s->next=temp;
            s=s->next;
        }
        head=head->next;
        Node* ans=reverse(head);
        return ans;
    }
        
};
