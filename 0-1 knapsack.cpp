class Solution
{
    public:
    int dp[1001][1001];

    
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       if(n==0||w==0)
       return 0;
       if(dp[n][w]!=-1)
       return dp[n][w];
         if(wt[n-1]<=w)
           {
               return dp[n][w]=max((val[n-1]+solve(w-wt[n-1],wt,val,n-1)),solve(w,wt,val,n-1));
           }
           else
           return dp[n][w]=solve(w,wt,val,n-1);
       
       
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       memset(dp, -1, sizeof(dp));
       return solve(w,wt,val,n);
      
       
    }
    
};
