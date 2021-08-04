class Solution {
public:
   void solve(vector<int>& candidates, int target,vector<vector<int>> &res,vector<int> &ds,int idx)
   {
       if( idx==candidates.size())
       {
           if(target==0)
           res.push_back(ds);
           return;
       }
       if(candidates[idx]<=target)
       {
           ds.push_back(candidates[idx]);
           solve(candidates,target-candidates[idx],res,ds,idx);
           ds.pop_back();
       }
       solve(candidates,target,res,ds,idx+1);
       
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> res;
        vector<int> ds;
        solve(candidates,target,res,ds,0);
        return res;
    }
};
