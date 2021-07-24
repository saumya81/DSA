class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.

  
    static long merger(long long int arr[], int l, int m, int r){
        int n1 = m-l+1;
        int n2 = r-m;
        long long int left[n1] ;
       long long int right[n2];

        for (int i = 0; i < n1; i++){
            left[i] = arr[l+i];// range l to m  
        }
        for (int i = 0; i < n2; i++){
            right[i] = arr[m+1+i];// range m to r 
        }
        int i = 0;
        int j = 0;
        int k = l;// as you are working from l to r starting wont be 0 , it will be l 
        long res = 0;
        while (i < n1 && j < n2){
            if (left[i]<=right[j]){
                arr[k] = left[i];
                k++;
                i++;
            }
            else{
                arr[k] = right[j];
                j++;
                k++;
                res+=(long)(n1-i);
            }
        }
        while (i<n1){
            arr[k] = left[i];
            k++;
            i++;
        }
        while (j<n2){
            arr[k] = right[j];
            k++;
            j++;
    }
    return res;
    }
      long long int  countInversions(long long int arr[], int l , int r){
        long res = 0;
        if (r > l){
            int mid = (l+r)/2;
            res+=countInversions(arr, l , mid);
            res+=countInversions(arr, mid+1, r);
            res+=merger(arr, l, mid, r);
        }
        return res;
    }
   
    long long int inversionCount(long long arr[], long long N)
    {
        return countInversions(arr, 0, (int)N-1);
    }

};
