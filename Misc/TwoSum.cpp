class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            int a=target-nums[i];
            if(m.find(a)!=m.end())
              {   
                v.push_back(m[a]);
                v.push_back(i);
                 return v;
              }
            m[nums[i]]=i;
           
        }
        return v;
    }
};
