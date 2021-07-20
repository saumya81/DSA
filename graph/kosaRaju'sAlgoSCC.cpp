//Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.
//There are three steps:
// 1.topological Sort
// 2. Transpose the graph
// 3. DFS on the transposed graph 
class Solution
{
	public:
    void topoSort(vector<int> adj[],int src,vector<bool> &visited,stack<int>& st)
	{
	    visited[src]=true;
	   
	    for(auto u:adj[src])
	    {
	        if(visited[u]==false)
	        topoSort(adj,u,visited,st);
	    }
	     st.push(src);
	}
    void reverseDFS(vector<int> adj[],int src,vector<bool> &visited)
	{
	    visited[src]=true;
	    for(auto u:adj[src])
	    {
	        if(visited[u]==false)
	        reverseDFS(adj,u,visited);
	    }
	}
    int kosaraju(int v, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(visited[i]==false)
            topoSort(adj,i,visited,st);
        }
       vector<int> adjTranspose[v];
       for(int i=0;i<v;i++)
       {
           visited[i]=false;
           for(auto u:adj[i])
           {
              adjTranspose[u].push_back(i);
           }
       }
       int count=0;
       while(!st.empty())
       {
           int src=st.top();
           st.pop();
           if(visited[src]==false)
           {reverseDFS(adjTranspose,src,visited);
               count++;
           }
       }
       
       return count; 
        
    }
};
