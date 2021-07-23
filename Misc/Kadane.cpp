 int maxSubarraySum(int a[], int n){
        
        int max_ending_here=0;
        int max_so_far=a[0];
        for(int i=0;i<n;i++)
        {
           max_ending_here=max_ending_here+a[i];
           if(max_ending_here>max_so_far)
           max_so_far=max_ending_here;
           if(max_ending_here<0)
           max_ending_here=0;
        }
        return max_so_far;
    }
