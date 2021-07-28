int maxLen(int a[], int n)
{
   unordered_map<int,int> m;
   int max=0;
   int curSum=0;
   for(int i=0;i<n;i++)
   {
       curSum+=a[i];
       if(curSum==0)
       max=i+1;
       else 
      { 
          if(m.find(curSum)==m.end())
            m[curSum]=i;
           else
           {
             int s=i-m[curSum];  
             max=max>=s?max:s;
           }
          
      }
   }
   return max;
}
