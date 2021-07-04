// Partition a number into two divisible parts 

// Given a number (as string) and two integers a and b, divide the string in two non-empty parts such that the first part is divisible by a and 
// the second part is divisible by b. 
// In case multiple answers exist, return the string such that the first non-empty part has minimum length.
  
// Input:
// 1200 4 3
// Output:
// 12 00
// Explanation:
// 12 is divisible by 4, and
// 00 is divisible by 3.



#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:

    string stringPartition(string s, int a, int b){
        // code here 
        int n=s.length();
        if(n<=1)
        return "-1";
        string s1="";
        int l=0,m=(l+n)/2;
       for(int i=0;i<n-1;i++)
        {
            s1=s1+s[i];
            if(stoi(s1)%a==0)
            {
               
                string s2= s.substr(i + 1);
                if(stoi(s2)%b==0)
                return s1+" "+s2;
            }
        }
       
        return "-1";
    }
};
