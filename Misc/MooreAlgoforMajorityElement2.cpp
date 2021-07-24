//Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int ele1=-1;
        int ele2=-1;
        int c1=0;
        int c2=0;
        for(int i=0;i<nums.size();i++)
        {
           if(nums[i]==ele1)
                c1++;
            else if(nums[i]==ele2)
                c2++;
            else if(c1==0)
              {  ele1=nums[i];
               c1++;
              }
            else if(c2==0)
                {ele2=nums[i];
                c2++;}
            
            else
                {c1--;c2--;}
            
        }
        c1=0;
        c2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ele1)
                c1++;
            else if (nums[i]==ele2)
                c2++;
            
                
        }
        vector<int> ans;
        if(c1>n/3)
            ans.push_back(ele1);
        if(c2>n/3)
            ans.push_back(ele2);
                     return ans;
                    
    }
};
