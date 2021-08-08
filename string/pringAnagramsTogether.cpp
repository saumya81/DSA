
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& s) {
        map<string,vector<string>> m;
        for(int i=0;i<s.size();i++)
        {
           string a=s[i];
           sort(a.begin(),a.end());
            m[a].push_back(s[i]);
        }
        
         vector<vector<string>> ans;
        for(auto it:m)
        {
           
               ans.push_back(it.second);
           
        }
        return ans;
        
        
    }
};
