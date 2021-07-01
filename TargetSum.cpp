// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".



class Solution {
public:
    int findTargetSumWays(vector<int>& a, int target) {
        int sum=0;
        for(int i=0;i<a.size();i++)
            sum=sum+a[i];
      if((sum+target)%2!=0 || sum<target)
          return 0;
        
    
          int s1=(sum+target)/2;
        int dp[a.size()+1][s1+1];
        
 
         for(int i=0;i<a.size()+1;i++)
            for(int j=0;j<s1+1;j++)
            {
            if(i==0)
                dp[i][j]=0;
                if(j==0)
                dp[i][j]=1;
            }
        
        
        for(int i=1;i<a.size()+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(a[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];          
                  }
                else
                    dp[i][j]=dp[i-1][j];
                    
            }
        }
        return dp[a.size()][s1];
        
    }
};
