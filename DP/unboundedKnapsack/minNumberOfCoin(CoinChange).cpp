class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int dp[M+1][V+1];
	    for(int i=0;i<M+1;i++)
	    {
	        for(int j=0;j<V+1;j++)
	        {
	            if(j==0)
	            dp[i][j]=0;
	            if(i==0)
	            dp[i][j]=INT_MAX-1;
	        }
	    }
	     for(int i=1;i<M+1;i++)
	    {
	        for(int j=1;j<V+1;j++)
	        {
               if(j>=coins[i-1])
               {
                   dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
               }
               else
               dp[i][j]=dp[i-1][j];
	        }
	    }
	    if(dp[M][V]==INT_MAX-1)
	    return -1;
	    return dp[M][V];
	    
	} 
	  
};
