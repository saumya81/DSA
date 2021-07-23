class Solution {
public:
   static bool comp(vector<int> t1,vector<int> t2)
    {
        return t1.front()<t2.front();
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0)
            return ans;
    ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++)
        {
          if(ans.back()[1]>=intervals[i][0])
          {
              ans.back()[1]=max(intervals[i][1],ans.back()[1]);
         }
            else
                ans.push_back(intervals[i]);
        }
        return ans;
        
    }
};
