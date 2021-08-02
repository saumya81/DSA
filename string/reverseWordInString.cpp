
// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
       stack<string> st;
       string s="";
       
       for(int i=0;i<S.length();i++)
       {
           if(S[i]==' '||S[i]=='.'||S[i]==',')
           {st.push(s);
          
           s=S[i];
               st.push(s);
               s="";
           }
           else
           s=s+S[i];
           
       }
       st.push(s);
       S="";
        while(!st.empty())
       {
          S=S+st.top();
          st.pop();
       }
       return S;
       
    } 
};
