//visitedRec is to keep the account of all the previous nodes that are visited

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int src,vector<int> adj[],vector<bool> &visited,vector<bool> visitedRec)
	{
	    visited[src]=true;
	    visitedRec[src]=true;
	    for(auto i:adj[src])
	    {
	        if(visited[i]==false && dfs(i,adj,visited,visitedRec))
	        return true;
	        if(visitedRec[i]==true)
	        return true;
	    }
	    visitedRec[src]=false;
	    return false;
	}
	bool isCyclic(int v, vector<int> adj[]) 
	{
	   	vector<bool> visited(v,false);
	   	vector<bool> visitedRec(v,false);
	   	for(int i=0;i<v;i++)
	   	{
	   	    if(visited[i]==false)
	   	    {
	   	        if(dfs(i,adj,visited,visitedRec)==true)
	   	        return true;
	   	        
	   	    }
	   	}
	   	return false;
	}
};
