// Given a weighted, undirected and connected graph of V vertices and E edges, Find the shortest distance of all the vertex's from the source vertex S.
// Note: The Graph doesn't contain any negative weight cycle.



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
       priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
       vector<int> dist(v+1,INT_MAX);
       dist[src]=0;
       pq.push({src,0});
       while(!pq.empty())
       {
           int curNode=pq.top().first;
           int curDist=pq.top().second;
           pq.pop();
           for(auto it:adj[curNode])
           {
              int nextNode=it[0];
              int nextDist=it[1];
              if(dist[nextNode]>curDist+nextDist)
              {
                  dist[nextNode]= curDist+nextDist;
                  pq.push({nextNode,dist[nextNode]});
                  
              }
              
           }
       }
       return dist;
       
    }
};
