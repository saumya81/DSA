class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        // your code here
        
         deque<int> dq;
         vector<int> ans;
        for (int i=0; i<n; i++) {
          //check if the element in list is smaller than the element we're going to add .. if it is smaller then we'll remove it
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();
            //check if the index in the list is smaller than the current window then also we don't need that in our list 
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        //  for the first time we need to check if it is greater than the window size then only push
            if (i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
