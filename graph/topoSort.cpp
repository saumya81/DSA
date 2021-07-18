// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
// such that for every directed edge uv, vertex u comes before v in the ordering.
// Topological Sorting for a graph is not possible if the graph is not a DAG. 


void DFS(int s,bool visited[],stack<int> &st,vector<int> adj[]){
        visited[s]=true;
        for(int x:adj[s]){
            if(visited[x]==false){
                DFS(x,visited,st,adj);
            }
        }
        st.push(s);
    }
    
    vector<int> topoSort(int V, vector<int> adj[]) 
    {   bool visited[V+1];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        vector<int> ans;
        stack<int>st;
        for(int i=0;i<V;i++){
            if(visited[i]==false){
                DFS(i,visited,st,adj);
            }
        }
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
