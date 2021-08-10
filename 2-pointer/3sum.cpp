
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int X)
    {
      //first we'll sort the array to apply 2 pointer approach means when sum of all 3 is less then we'll increase low else if sum is more we'll decrease high
       sort(arr,arr+n);
        for(int i=0;i<n-2;i++)
        {
            int a=arr[i];
            int l=i+1;
            int h=n-1;

            while(l<h)
            {
                if(arr[l]+arr[h]+arr[i]==X)
                return true;
                else if(arr[l]+arr[h]+arr[i]<X)
                l++;
                else
                h--;
            }
        }
        return false;
    }

};
