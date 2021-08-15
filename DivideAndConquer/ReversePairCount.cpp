class Solution {
public:
    int merge(vector<int>& nums,int l,int mid,int h)
     {
       
        int c=0,p=mid+1;
      //count the number of reverse pair
        for(int i=l;i<=mid;i++)
        {
            while(p<=h && nums[i]>nums[p]*2LL)
                p++;
            c+=p-(mid+1);
        }
          int n1=mid-l+1;
         int n2=h-mid;
         int a[n1],b[n2];
         for(int i=0;i<n1;i++)
             a[i]=nums[l+i];
        
         for(int i=0;i<n2;i++)
             b[i]=nums[mid+i+1];
        
         int i=0,j=0,k=l;
        
         while(i<n1&&j<n2){
             if(a[i]<=b[j])
                { nums[k]=a[i];
                i++;
                k++;}
             else
                { nums[k]=b[j];
                k++;
                j++;}
             
         }
          while (i<n1){
            nums[k] = a[i];
            k++;
            i++;
        }
        while (j<n2){
            nums[k] = b[j];
            k++;
            j++;
    }
         return c;
     }
    int mergeSort(vector<int>& nums,int l,int h)
    {
        int count=0;
        if(l<h)
        {
            int mid=(l+h)/2;
             count+=mergeSort(nums,l,mid);
             count+=mergeSort(nums,mid+1,h);
             count+=merge(nums,l,mid,h);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};
