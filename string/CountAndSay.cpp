 string countAndSay(int n) {
        if(n == 1)
            return "1";
        if(n==2)
            return "11";
        string s="11";
        for(int i=3;i<=n;i++)
        {
            string t="";
            int c=1;
            s=s+'&'; // delimeter this is to know that we have reached last element
            int len=s.length();
            for(int j=1;j<len;j++)
            {
                if(s[j]!=s[j-1])
                {
         t=t+to_string(c); // if they arn't equal convert count to string n add to t n reset count to 1
                    t=t+s[j-1];
                    c=1;
                }
                else
                    c++; // count to see no of characters are same
            }
            s=t;
        }
        return s;
    }
