class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length()%2!=0)
            return false;
       
      for(int i=0;i<s.length();i++)
      {
          if(st.size()==0 || s[i]=='(' ||s[i]=='{'||s[i]=='[')
              st.push(s[i]);
          else
          {
             
              if((st.top() == '{' && s[i] == '}') || (st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']'))
                st.pop(); 
              else
                  st.push(s[i]);
              
          }
          
              
      }
        return st.size()==0?true:false;
    }
};
