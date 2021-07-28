class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int solve(int x, int y, string s1, string s2,vector<vector<int>> &dp)
    {
       if(x==0||y==0)
        return 0;
        else if(dp[x][y]!=-1)
        return dp[x][y];
        else if(s1[x-1]==s2[y-1])
        return dp[x][y]= 1+solve(x-1,y-1,s1,s2,dp);
        else
        return dp[x][y]=max(solve(x-1,y,s1,s2,dp),solve(x,y-1,s1,s2,dp)); 
    }
    int lcs(int x, int y, string s1, string s2)
    {
       vector<vector<int>> dp( x+1 , vector<int> (y+1, -1));
      
        return solve(x,y,s1,s2,dp);
    }
};
