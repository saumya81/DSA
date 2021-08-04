class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m,int n,
    vector<vector<int>> &visited,vector<string> &ans,string path,int di[],int dj[])
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        string direction="DLRU";
        for(int idx=0;idx<4;idx++)
        {
            int nexti=i+di[idx];
            int nextj=j+dj[idx];
            if(nexti>=0 && nextj>=0 && nexti<n && nextj<n 
            && m[nexti][nextj]==1 && visited[nexti][nextj]==0)
            {
                visited[i][j]=1;
                solve(nexti,nextj,m,n,visited,ans,path+direction[idx],di,dj);
                visited[i][j]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
       vector<vector<int>> vis(n,vector<int>(n,0));
       vector<string> ans;
       int di[]={1,0,0,-1};
       int dj[]={0,-1,1,0};
       if(m[0][0]==1)
       solve(0,0,m,n,vis,ans,"",di,dj);
       return ans;
       
    }
};
