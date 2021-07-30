class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      
        int k=0;
       int maxi=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                k=k+1;
                maxi=max(maxi,k);
            }
            if(nums[i]==0)
                k=0;
                
            
        }
      
        return maxi;
    }
};
