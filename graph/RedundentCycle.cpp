//https://leetcode.com/problems/redundant-connection/description/

// In this problem, a tree is an undirected graph that is connected and has no cycles.

// You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

// Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

// Example 1:


// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]
// Example 2:


// Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
// Output: [1,4]


class Solution {
public:
    bool dfs(int src, int parent, vector<int> adj[], vector<int>& vis){
        vis[src] = 1; 

        for(auto it: adj[src]){
            if(!vis[it]){
            if(dfs(it,src,adj,vis))
            return true;}
            else if(it !=parent)
            return true;
        }
    
      return false; 

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m=edges.size();
        int n= edges[0].size();

        vector<int> vis(m+1,0);
        vector<int> adj[m+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
         vector<int> vis(m + 1, 0);
            if (dfs(edges[i][0], -1, adj, vis)) {
                return edges[i];
            }
        }


        return {};

    }
};
