class Solution 
{
    public:
    bool dfs(int src,vector<int> adj[],vector<bool> &visited,int parent)
    {
        visited[src]=true;
       
        for(auto u:adj[src])
        {
            if(visited[u]==false )
            {
            if( dfs(u,adj,visited,src))
            return true;}
            else if(u!=parent)
            return true;
        }
            return false;
      
            
        
    }
	bool isCycle(int v, vector<int>adj[])
	{
	    vector<bool> visited(v,false);
	    for(int i=0;i<v;i++){
	        if(visited[i]==false )
	        {
	            if(dfs(i,adj,visited,-1)==true)
	            return true;
	        }
    
	    }
	    return false;
	}
};
