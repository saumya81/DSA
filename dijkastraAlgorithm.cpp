
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        vector<int> dist(v+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[s]=0;
        pq.push(make_pair(0,s));
        while(!pq.empty())
        {
            int curDist=pq.top().first;
            int node=pq.top().second;
          //vector<vector<int>>::iterator it;
          pq.pop();
            for(auto it: adj[node])
            {

                int nextNode=it[0];
                int nextDistance=it[1];
                if(dist[nextNode]>curDist+nextDistance)
                {
                  dist[nextNode]= curDist+nextDistance;
                  pq.push(make_pair(dist[nextNode],nextNode));
                }
            }
            
            
        }
        return dist;
        
    }
};
