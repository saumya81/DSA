//here we select the minimum and swap with the index


class Solution
{
    
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
     for(int i=0;i<=n-2;i++)
     {
         int imin=i;//let current index has minimum
         for(int j=i+1;j<n;j++)
         {
             if(arr[imin]>arr[j])
             {
                 imin=j;
             }
         }
       //swaping current index with actual minimum
         int temp=arr[imin];
         arr[imin]=arr[i];
         arr[i]=temp;
     }
    }
};
