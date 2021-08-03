class Solution{
  public:
    int minLen(string arr[],int  N)
    {
        int min=arr[0].length();
        for(int i=1;i<N;i++)
        {
            if(arr[i].length()<min)
            min=arr[i].length();
        }
        return min;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        int minlen=minLen(arr,N);
        string result; 
    char current; 
 
    for (int i=0; i<minlen; i++)
    {
        
        current = arr[0][i];
 
        for (int j=1 ; j<N; j++)
            if (arr[j][i] != current)
               if(result.length()>0)
                return (result);
                else
                return "-1";
 
        
        result.push_back(current);
    }
    if(result.length()>0)
    return (result);
    else
    return "-1";
    }
};
