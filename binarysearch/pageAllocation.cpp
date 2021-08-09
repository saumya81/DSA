/ Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages.
// Every student is assigned to read some consecutive books.
// The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum. 


#include <bits/stdc++.h>
using namespace std;
bool isAllocationPossible(int mid,int a[],int n,int student){
    int studentAllocated=1;
    int pages=0;
    
   
    for(int i=0;i<n;i++)
    {
        if(a[i]>mid)
        return false;
        if(pages+a[i]>mid)
        {
            pages=a[i];
            studentAllocated+=1;
            if(studentAllocated>student)
            return false;
        }
        else{
            pages=pages+a[i];
        }
    }
    return true;

}
int allocatepages(int a[],int n,int student)
{
    int l=0;
    int h=0;
    for(int i=0;i<n;i++)
    h=h+a[i];
    if(l>h)
    return -1;
    int res = INT_MAX;
    while(l<=h){
        int mid=(l+h)/2;
        if(isAllocationPossible(mid,a,n,student))
        {
            res=mid;
            h=mid-1;
        }
        else
        l=mid+1;
    }
    return res;
}
int main() {
    int n ;
    cin>>n;
    int a[n];
    int h;
    for(int i=0;i<n;i++)
  {  cin>>a[i];
  h=h+a[i];
  }
    int student;
    cin>>student;
  
    
   int answer= allocatepages(a,n,student);
   cout<<answer;

}
