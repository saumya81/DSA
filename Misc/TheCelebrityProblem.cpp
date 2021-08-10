https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 

Example 1:

Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1
Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity. 
  
  
  
----------------------------------------------------------------------------------------------------------------------------------  
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int c=0;
      //we made at first celebrity=0 and then checking if it knows anyone or not,and if it knows the celebrity gets updated to the person he knows
      //as he can be a possible candidate ,this way the loop runs and get the possible candidate
        for(int i=0;i<n;i++)
        {
            if(M[c][i]==1)
            c=i;
        }
       
       //final check if he celebrity knoes no one and everyone knows him 
        for(int i=0;i<n;i++)
        {
            if(i!=c && (M[c][i]==1 ||  M[i][c]==0))
            return -1;
        }
        return c;
    }
};
