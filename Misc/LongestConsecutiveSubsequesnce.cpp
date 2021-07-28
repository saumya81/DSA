class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int N)
    {
      set<int> s;
        for(int i=0;i<N;i++)
            s.insert(a[i]);
    int currentNum=0;
    int currentStreak;
    int maxStreak=-1;
    for(auto it=s.begin();it!=s.end();it++)
    {
       if(s.find(*it-1)==s.end())
       {
           currentNum=*it;
           currentStreak=1;
           while(s.find(currentNum+1)!=s.end())
           {
               currentNum=currentNum+1;
               currentStreak=currentStreak+1;
               it++;
           }
           maxStreak=maxStreak<=currentStreak?currentStreak:maxStreak;
       }
    }
    return maxStreak;
       
    }
};
