//intution behind this is .. we'll create a min heap which will have smallest elemnt in top so we'll take 2 smallest element 
//add them to the answer and then again put that sum of 2 element in the heap

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long> > q;
        for(int i=0;i<n;i++)
        {
          q.push(arr[i]);  
        }
        long long sum=0;
        while(q.size()>=2)
        {
            long long first=q.top();
            q.pop();
            long long second=q.top();
            q.pop();
            sum=sum+first+second;
            q.push(first+second);
        }
        return sum;
    }
};
