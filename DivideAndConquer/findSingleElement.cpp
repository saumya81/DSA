You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. 
Find this single element that appears only once.

Follow up: Your solution should run in O(log n) time and O(1) space.

 

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2



--------------------------------------

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0;
        int h=nums.size()-2;
        while(l<=h)
        {
            int mid=(l+h)>>1;
            if(nums[mid]==nums[mid^1])//if it is odd it will give previous even ,if it is even it will give next odd
            {
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return nums[l];
    }
};
