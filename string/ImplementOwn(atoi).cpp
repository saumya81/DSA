class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int n=str.length();
        int i=0;
        int sign=1;
        int number=0;
        if(str[i]=='-')
        {sign=-1;
            i+=1;
        }
        while(i<n)
        {
            if(str[i]-'0'>=0 && str[i]-'0'<=9)
            {
                number=number*10+(str[i]-'0');
            }
            else
            return -1;
            i++;
        }
        return number*sign;
    }
};
