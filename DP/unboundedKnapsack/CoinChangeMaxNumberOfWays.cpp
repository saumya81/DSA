// Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.


// Example 1:

// Input:
// n = 4 , m = 3
// S[] = {1,2,3}
// Output: 4
// Explanation: Four Possible ways are:
// {1,1,1,1},{1,1,2},{2,2},{1,3}.





class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
       
        long long int dp[m+1][n+1];
       for( long long int i=0;i<=m;i++)
       {
           for( long long int j=0;j<=n;j++)
           {
               if(i==0)
               dp[i][j]=0;
               if(j==0)
               dp[i][j]=1;
           }
       }
        for( long long int i=1;i<=m;i++)
       {
           for( long long int j=1;j<=n;j++)
           {
              if(S[i-1]<=j)
              {
                  dp[i][j]=dp[i-1][j]+dp[i][j-S[i-1]];
              }
              else
              dp[i][j]=dp[i-1][j];
           }
       }
       return dp[m][n];
       
    }
};
