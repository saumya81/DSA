The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.


-------------------------------------------------------------------------------------------------
class Solution {
public:
    string getPermutation(int n, int k) {
       vector<int> nums;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            nums.push_back(i);
            fact=fact*i;
        }
        nums.push_back(n);
        string ans="";
        k=k-1 ; // as we're using 0 based indexing
            while(true)
            {
                ans=ans+to_string(nums[k/fact]);
                nums.erase(nums.begin()+k/fact);
                if(nums.size()==0)
                    break;
                k=k%fact;
                fact=fact/nums.size();
            }
        return ans;
    }
};
