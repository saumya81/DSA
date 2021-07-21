// we made a key array to store the weight, mstSet array to keep the track of parent
//we used priority queue to get the minimum weight always as we need to process minimum first


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<int> key(v,INT_MAX);
        vector<bool> mstSet(v,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        key[0]=0;
        pq.push({key[0],0});
        while(!pq.empty())
        {
            int u=pq.top().second;
            mstSet[u]=true;
            pq.pop();
            for(auto it:adj[u])
            {
                int wt=it[1];
                int v=it[0];
                if(mstSet[v]==false && wt<key[v])
                {
                    key[v]=wt;
                    pq.push({key[v],v});
                }
                
            }
        }
        int sum=0;
        for(int i=0;i<v;i++)
        {
            sum=sum+key[i];
        }
        return sum;
    }
};
