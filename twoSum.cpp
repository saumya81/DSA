class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
      int d;
        unordered_map<int,int> m;
        vector<int> v;
        for(int i=0;i<a.size();i++)
        {
            d=t-a[i];
            if(m.find(d)!=m.end())
            {
                v.push_back(i);
                v.push_back(m[d]);
                return v;
                
            }
            m[a[i]]=i;
        }
        return v;
    }
};
