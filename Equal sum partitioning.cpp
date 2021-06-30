// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].




class Solution {
public:
    bool subsetSum(vector<int> a,int s)
    {
        int n=a.size();
        
      bool dp[n+1][s+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<s+1;j++)
            { 
                if(i==0)
                 dp[i][j]=false;
                if(j==0)
                 dp[i][j]=true;
               }}

          for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<s+1;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j] | dp[i-1][j-a[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][s];
    }
    bool canPartition(vector<int>& a) {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum=sum+a[i];
      //it cannot be possible if sum of element is odd
        if(sum%2!=0)
            return false;
        else
            return subsetSum(a,sum/2);
        
    }
};
