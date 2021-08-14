Given a string str, a partitioning of the string is a palindrome partitioning if 
every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of given string.



Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".

--------------------------------------------------------------------------------------------------


class Solution{
public:
 int dp[1000][1000];
bool ispallindrome(string s,int i,int j)
{
    
    while(i<j)
    {
        if(s[i]!=s[j])
        return false;
        i++;
        j--;
    }
    return true;
}
int solve(string str,int i,int j)
{
    if(i>=j)
    return 0;
    if(ispallindrome(str,i,j))
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        
        int temp=1+(dp[i][k]==-1?solve(str,i,k):dp[i][k])+(dp[k+1][j]==-1?solve(str,k+1,j):dp[k+1][j]);
        if(temp<min)
        min=temp;
        
    }
    return dp[i][j]=min;
}
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        int min =solve(str,0,str.length()-1);
        return min;
        
    }
};
