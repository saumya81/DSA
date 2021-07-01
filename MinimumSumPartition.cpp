	
// Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference

// Example 1:

// Input: N = 4, arr[] = {1, 6, 11, 5} 
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
  
  
  
  int minDifference(int a[], int n)  { 
	   int sum=0;
	    for(int i=0;i<n;i++)
	        sum=sum+a[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<n+1;i++)
	    for(int j=0;j<sum+1;j++)
	    {
	        if(i==0)
	        dp[i][j]=false;
	        if(j==0)
	        dp[i][j]=true;
	    }
	    
	     for(int i=1;i<n+1;i++){
	    for(int j=1;j<sum+1;j++)
	    {
	       if(a[i-1]<=j)
	       dp[i][j]=dp[i-1][j] | dp[i-1][j-a[i-1]];
	
	       else
	       dp[i][j]=dp[i-1][j];
	       
	    }
	         
	     }
	   int diff = INT_MAX;

    for (int j=sum/2; j>=0; j--)
    {
        // Find the
        if (dp[n][j] == true)
        {
            diff = sum-2*j;
            break;
        }
    }
    return diff;
	    
	} 
