
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool ispossible(int node,bool graph[101][101], int m, int n,int color[],int curColor)
{
    for(int i=0;i<n;i++)
    {
        if(i!=node && graph[i][node]==1 && color[i]==curColor )
        return false;
    }
    return true;
}
bool solve(int node,bool graph[101][101], int colorlen, int n,int color[])
{
    if(node==n)
    return true;
    //i specify color
    for(int i=1;i<=colorlen;i++){
    if(ispossible(node,graph,colorlen,n,color,i))
    {
        color[node]=i;
        if(solve(node+1,graph,colorlen,n,color))
        
    return true;
    color[node]=0;
        
    }
        
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int v)
{
    
    int color[v]={0};
    if(solve(0,graph,m,v,color))
    return true;
    return false;
}
