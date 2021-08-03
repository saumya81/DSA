
//this question is same asthat of longest common subsequence .. 
//there we were getting two string but here we got one string and the other will be reverse of the given string

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        string revS=string(s.rbegin(),s.rend());
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<n+1;j++)
                if(i==0||j==0)
                    dp[i][j]=0;
        }
         for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(s[i-1]==revS[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    }
                else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
