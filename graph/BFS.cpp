class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
    void BFS(vector<int> adj[],int src,int visited[],vector<int> &ans)
    {
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
           int  u=q.front();
           q.pop();
            ans.push_back(u);
            for(auto i :adj[u])
            {
                if(visited[i]==false)
               { q.push(i);
                   visited[i]=true;
               }
            }
        }
    }
	vector<int>bfsOfGraph(int v, vector<int> adj[])
	{
	   
	    vector<int> ans;
	    int visited[v]={false};
	    for(int i=0;i<v;i++)
	    {
	        if(visited[i]==false)
	        BFS(adj,i,visited,ans);
	        return ans;
	    }
	    
	}
};
