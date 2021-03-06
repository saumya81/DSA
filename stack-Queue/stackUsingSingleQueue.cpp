class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    MyStack() {
       
    }
    
    /** Push element x onto stack. */
    void push(int x) {
       q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
			q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x=q.front();
        q.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
       int x=q.front();
      
        return x; 
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
