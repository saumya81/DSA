class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void dfs(int src,vector<int> adj[],vector<bool> &visited,vector<int> & ans)
	{
	    visited[src]=true;
	    ans.push_back(src);
	    for(auto u:adj[src])
	    {
	        if(visited[u]==false)
	        dfs(u,adj,visited,ans);
	    }
	    
	}
	vector<int> dfsOfGraph(int v, vector<int> adj[])
	{
	    // Code here
	     vector<bool> visited(v,false);
	    	vector<int> ans;
	    for(int i=0;i<v;i++)
	    {
	        if(visited[i]==false)
	        {
	            dfs(i,adj,visited,ans);
	        }
	    }
	    return ans;
	}
};
