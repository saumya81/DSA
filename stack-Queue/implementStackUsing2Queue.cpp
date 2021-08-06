
/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
queue<int> q1,q2;
void QueueStack :: push(int x)
{
       
        // Push x first in empty q2
        q2.push(x);
  
        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
  
        // swap the names of two queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code  
         if (q1.empty())
            return -1;
            int x=q1.front();
            q1.pop();
        return x;
        
}
