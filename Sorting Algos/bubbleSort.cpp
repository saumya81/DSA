//here we compare only from the next index , this way the highest element will come to it's correct position after every iteration.
//flag to check if there is no swapping means all elements are in their correct position and we can say that array is sorted
class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int arr[], int n)
    {
        for(int i=0;i<n-1;i++)
        {
           bool flag=true;
            for(int j=0;j<n-i-1;j++ )
            {
                if(arr[j]>arr[j+1])
                {
                    int temp=arr[j+1];
                    arr[j+1]=arr[j];
                    arr[j]=temp;
                    flag=false;
                }
            }
            if(flag)
            break;
            
        }
    }
};
