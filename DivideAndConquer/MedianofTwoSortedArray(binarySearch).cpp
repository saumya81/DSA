Given two sorted arrays array1 and array2 of size m and n respectively. Find the median of the two sorted arrays.

Example 1:

Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5

-----------------------------------------------------------------------------------------------------

double MedianOfArrays(vector<int>& array1, vector<int>& array2)
{
    
    int len1=array1.size();
    int len2=array2.size();
    if(len1>len2)
    return MedianOfArrays(array2,array1);
   int l=0;
   int h=len1;
   int mid=(len1+len2+1)/2;
   while(l<=h)
   {
       int cut1=(l+h)/2;
       int cut2=mid-cut1;
       int l1=cut1==0?INT_MIN:array1[cut1-1];
       int l2=cut2==0?INT_MIN:array2[cut2-1];
       int r1=cut1==len1?INT_MAX:array1[cut1];
       int r2=cut2==len2?INT_MAX:array2[cut2];
       if(l1<=r2 && l2<=r1)
       {
           if((len1+len2)%2==0)
           {
               return((max(l1,l2)+min(r1,r2))/2.0);
           }
           else
           return max(l1,l2);
       }
       else
       {
           if(l1>r2)
           h=cut1-1;
           else
           l=cut1+1;
       }
       
   }
   return -1;
    
}
