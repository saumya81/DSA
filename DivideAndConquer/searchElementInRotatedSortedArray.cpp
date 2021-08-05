class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int h=nums.size()-1;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]==target)
                return mid;
            if(nums[l]<=nums[mid])//left half  is sorted
            {
                if(nums[l]<=target && target<=nums[mid])
                h=mid-1;
                else
                    l=mid+1;
            }
            else //right half is sorted
            {
                if(nums[mid]<=target && target<=nums[h])
               l=mid+1;
                else
                    h=mid-1;
            }
            
      
        }
       
            return -1;
        
    }
};
